/* WiFi station Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_event.h"
#include "esp_wifi.h"
#include "nvs.h"
#include "nvs_flash.h"

#include "tcpip_adapter.h"
#include "esp_smartconfig.h"
#include "smartconfig_ack.h"
#include "driver/gpio.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#include "mqtt_client.h"

/* The examples use WiFi configuration that you can set via project configuration menu

   If you'd rather not, just change the below entries to strings with
   the config you want - ie #define EXAMPLE_WIFI_SSID "mywifissid"
*/
#define EXAMPLE_ESP_WIFI_SSID      CONFIG_ESP_WIFI_SSID
#define EXAMPLE_ESP_WIFI_PASS      CONFIG_ESP_WIFI_PASSWORD
// #define EXAMPLE_ESP_WIFI_PASS      "wrongPassword123"
#define EXAMPLE_ESP_MAXIMUM_RETRY  CONFIG_ESP_MAXIMUM_RETRY

/* The examples use smartconfig type that you can set via project configuration menu.

   If you'd rather not, just change the below entries to enum with
   the config you want - ie #define EXAMPLE_ESP_SMARTCOFNIG_TYPE SC_TYPE_ESPTOUCH
*/
#define EXAMPLE_ESP_SMARTCOFNIG_TYPE      SC_TYPE_ESPTOUCH

/* The event group allows multiple bits for each event, but we only care about two events:
 * - we are connected to the AP with an IP
 * - we failed to connect after the maximum amount of retries */
#define WIFI_CONNECTED_BIT      BIT0
#define WIFI_FAIL_BIT           BIT1
#define SMART_CONFIG_DONE_BIT   BIT2

#define GPIO_OUTPUT_IO_0    0
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<GPIO_OUTPUT_IO_0)

#define RELAY_ON  1
#define RELAY_OFF 0

static int g_relay_status = RELAY_OFF;

static const char *TAG = "wifi station";

static int s_retry_num = 0;
/* FreeRTOS event group to signal when we are connected*/
static EventGroupHandle_t s_wifi_event_group;

static esp_err_t mqtt_event_handler(esp_mqtt_event_handle_t event);

static void relay_ctrl(int status)
{
    g_relay_status = status;
    gpio_set_level(GPIO_OUTPUT_IO_0, g_relay_status); 
}

static void event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        if (s_retry_num < EXAMPLE_ESP_MAXIMUM_RETRY) {
            esp_wifi_connect();
            s_retry_num++;
            ESP_LOGI(TAG, "retry to connect to the AP");
        } else {
            xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);
        }
        ESP_LOGI(TAG,"connect to the AP fail");
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        ESP_LOGI(TAG, "got ip:%s",
                 ip4addr_ntoa(&event->ip_info.ip));
        s_retry_num = 0;
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
    } else if (event_base == SC_EVENT && event_id == SC_EVENT_SCAN_DONE) {
        ESP_LOGI(TAG, "Scan done");
    } else if (event_base == SC_EVENT && event_id == SC_EVENT_FOUND_CHANNEL) {
        ESP_LOGI(TAG, "Found channel");
    } else if (event_base == SC_EVENT && event_id == SC_EVENT_GOT_SSID_PSWD) {
        ESP_LOGI(TAG, "Got SSID and password");

        smartconfig_event_got_ssid_pswd_t* evt = (smartconfig_event_got_ssid_pswd_t*)event_data;
        wifi_config_t wifi_config;
        uint8_t ssid[33] = { 0 };
        uint8_t password[65] = { 0 };
        uint8_t rvd_data[33] = { 0 };

        bzero(&wifi_config, sizeof(wifi_config_t));
        memcpy(wifi_config.sta.ssid, evt->ssid, sizeof(wifi_config.sta.ssid));
        memcpy(wifi_config.sta.password, evt->password, sizeof(wifi_config.sta.password));
        wifi_config.sta.bssid_set = evt->bssid_set;

        if (wifi_config.sta.bssid_set == true) {
            memcpy(wifi_config.sta.bssid, evt->bssid, sizeof(wifi_config.sta.bssid));
        }

        memcpy(ssid, evt->ssid, sizeof(evt->ssid));
        memcpy(password, evt->password, sizeof(evt->password));
        ESP_LOGI(TAG, "SSID:%s", ssid);
        ESP_LOGI(TAG, "PASSWORD:%s", password);
        if (evt->type == SC_TYPE_ESPTOUCH_V2) {
            ESP_ERROR_CHECK( esp_smartconfig_get_rvd_data(rvd_data, sizeof(rvd_data)) );
            ESP_LOGI(TAG, "RVD_DATA:%s", rvd_data);
        }

        ESP_ERROR_CHECK(esp_wifi_disconnect());
        ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));
        ESP_ERROR_CHECK(esp_wifi_connect());
    } else if (event_base == SC_EVENT && event_id == SC_EVENT_SEND_ACK_DONE) {
        xEventGroupSetBits(s_wifi_event_group, SMART_CONFIG_DONE_BIT);
    }
}

static void smartconfig_init_start(void)
{
    EventBits_t uxBits;
    ESP_ERROR_CHECK(esp_smartconfig_set_type(EXAMPLE_ESP_SMARTCOFNIG_TYPE));
    smartconfig_start_config_t cfg = SMARTCONFIG_START_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_event_handler_register(SC_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL));
    ESP_ERROR_CHECK(esp_smartconfig_start(&cfg));
    printf("smartconfig start ....... \n");

    while (1) {
        uxBits = xEventGroupWaitBits(s_wifi_event_group, WIFI_CONNECTED_BIT | SMART_CONFIG_DONE_BIT, true, false, portMAX_DELAY);

        if (uxBits & WIFI_CONNECTED_BIT) {
            ESP_LOGI(TAG, "WiFi Connected to ap");
        }

        if (uxBits & SMART_CONFIG_DONE_BIT) {
            ESP_LOGI(TAG, "smartconfig over");
            esp_smartconfig_stop();
            break;
        }
    }

    ESP_ERROR_CHECK(esp_event_handler_unregister(SC_EVENT, ESP_EVENT_ANY_ID, &event_handler));
}

void wifi_init_sta(void)
{
    s_wifi_event_group = xEventGroupCreate();

    tcpip_adapter_init();

    ESP_ERROR_CHECK(esp_event_loop_create_default());

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL));


    wifi_config_t wifi_config = {
        .sta = {
            .ssid = EXAMPLE_ESP_WIFI_SSID,
            .password = EXAMPLE_ESP_WIFI_PASS
        },
    };

    /* Setting a password implies station will connect to all security modes including WEP/WPA.
        * However these modes are deprecated and not advisable to be used. Incase your Access point
        * doesn't support WPA2, these mode can be enabled by commenting below line */

    if (strlen((char *)wifi_config.sta.password)) {
        wifi_config.sta.threshold.authmode = WIFI_AUTH_WPA2_PSK;
    }

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config) );
    ESP_ERROR_CHECK(esp_wifi_start() );

    ESP_LOGI(TAG, "wifi_init_sta finished.");

    /* Waiting until either the connection is established (WIFI_CONNECTED_BIT) or connection failed for the maximum
     * number of re-tries (WIFI_FAIL_BIT). The bits are set by event_handler() (see above) */
    EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
            WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
            pdFALSE,
            pdFALSE,
            portMAX_DELAY);

    /* xEventGroupWaitBits() returns the bits before the call returned, hence we can test which event actually
     * happened. */
    if (bits & WIFI_CONNECTED_BIT) {
        ESP_LOGI(TAG, "connected to ap SSID:%s password:%s",
                 EXAMPLE_ESP_WIFI_SSID, EXAMPLE_ESP_WIFI_PASS);
    } else if (bits & WIFI_FAIL_BIT) {
        ESP_LOGI(TAG, "Failed to connect to SSID:%s, password:%s",
                 EXAMPLE_ESP_WIFI_SSID, EXAMPLE_ESP_WIFI_PASS);
        smartconfig_init_start();
    } else {
        ESP_LOGE(TAG, "UNEXPECTED EVENT");
        smartconfig_init_start();
    }

    ESP_ERROR_CHECK(esp_event_handler_unregister(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler));
    ESP_ERROR_CHECK(esp_event_handler_unregister(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler));
    vEventGroupDelete(s_wifi_event_group);
}

static void relay_gpio_init(void)
{
    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO15/16
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);
}

/* MQTT事件处理函数 */
static esp_err_t mqtt_event_handler(esp_mqtt_event_handle_t event)
{
    char mag_data[100];
    // 获取MQTT客户端结构体指针
    esp_mqtt_client_handle_t client = event->client;

    // 通过事件ID来分别处理对应的事件
    switch (event->event_id) 
    {
        // 建立连接成功
        case MQTT_EVENT_CONNECTED:
            printf("MQTT_client cnnnect to EMQ ok. \n");
            // 发布主题，主题消息为“I am ESP32.”,自动计算有效载荷，qos=1
            esp_mqtt_client_publish(client, "ESP8266_Publish", "I am ESP8266.", 0, 1, 0);
            // 订阅主题，qos=0
            esp_mqtt_client_subscribe(client, "ESP8266_Subscribe", 0);
            break;
        // 客户端断开连接   
        case MQTT_EVENT_DISCONNECTED:
            printf("MQTT_client have disconnected. \n");
            break;
        // 主题订阅成功
        case MQTT_EVENT_SUBSCRIBED:
            printf("mqtt subscribe ok. msg_id = %d \n",event->msg_id);
            break;
        // 取消订阅
        case MQTT_EVENT_UNSUBSCRIBED:
            printf("mqtt unsubscribe ok. msg_id = %d \n",event->msg_id);
            break;
        // 主题发布成功
        case MQTT_EVENT_PUBLISHED:
            printf("mqtt published ok. msg_id = %d \n",event->msg_id);
            break;
        // 已收到订阅的主题消息
        case MQTT_EVENT_DATA:
            printf("mqtt received topic: %.*s \n",event->topic_len, event->topic);
            printf("topic data: [%.*s]\r\n", event->data_len, event->data);
            sprintf(mag_data,"%.*s",event->data_len, event->data);
            if(strcmp(mag_data,"RELAY_ON") == 0)
            {
                relay_ctrl(RELAY_ON);
            }      
            else if(strcmp(mag_data,"RELAY_OFF") == 0)
            {
                relay_ctrl(RELAY_OFF);
            }
            else if (strcmp(mag_data,"RELAY_IS") == 0)
            {
                if(g_relay_status == RELAY_ON)
                    esp_mqtt_client_publish(client, "ESP8266_Publish", "RELAY_STATE_ON", 0, 1, 0);
                else
                    esp_mqtt_client_publish(client, "ESP8266_Publish", "RELAY_STATE_OFF", 0, 1, 0);
            }    
            break;
        // 客户端遇到错误
        case MQTT_EVENT_ERROR:
            printf("MQTT_EVENT_ERROR \n");
            break;

        case MQTT_EVENT_ANY:
        case MQTT_EVENT_BEFORE_CONNECT:
            break;
    }
    return ESP_OK;
}

static void mqtt_init(void)
{
    // 1、定义一个MQTT客户端配置结构体，输入MQTT的url和MQTT事件处理函数
    esp_mqtt_client_config_t mqtt_cfg = {
        .uri = "mqtt://192.168.3.17",
        .client_id = "ESP8266_MQTT",
        .username = "ESP8266_RELAY",
        .event_handle = mqtt_event_handler,
    };

   // 2、通过esp_mqtt_client_init获取一个MQTT客户端结构体指针，参数是MQTT客户端配置结构体
    esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);

	// 3、开启MQTT
    esp_mqtt_client_start(client);
}

void app_main()
{
    ESP_ERROR_CHECK(nvs_flash_init());

    relay_gpio_init();

    ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
    wifi_init_sta();

    mqtt_init();
}
