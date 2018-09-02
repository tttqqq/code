import controller.*;

public class GreenhouseControls extends Controller {
    //灯控制
    private boolean light = false;
    public class LightOn extends Event{
        public LightOn(long delayTime){
            super(delayTime);
        }
        public void action(){
            light = true;
        }
        public String toString(){
            return "Light is on";
        }
    }
    public class LightOff extends Event{
        public LightOff(long delayTime){
            super(delayTime);
        }
        public void action(){
            light = false;
        }
        public String toString(){
            return "Light is off";
        }
    }

    //水控制
    private boolean water  = false;
    public class WaterOn extends Event{
        public WaterOn(long delayTime){
            super(delayTime);
        }
        public void action(){
            water = true;
        }
        public String toString(){
            return  "Greenhouse water is on";
        }
    }
    public class WaterOff extends Event{
        public WaterOff(long delayTime){
            super(delayTime);
        }
        public void action(){
            water = false;
        }
        public String toString(){
            return  "Greenhouse water is off";
        }
    }

    //恒温调节器
    private String thermostat = "Day";
    public class ThermostatNight extends Event{
        public ThermostatNight(long delayTime){
            super(delayTime);
        }
        public void action(){
            thermostat = "Night";
        }
        public String toString(){
            return  "Thermostat on night setting";
        }
    }
    public class ThermostatDay extends Event{
        public ThermostatDay(long delayTime){
            super(delayTime);
        }
        public void action(){
            thermostat = "Day";
        }
        public String toString(){
            return  "Thermostat on day setting";
        }
    }

    //门铃
    public class Bell extends Event{
        public Bell(long delayTime) {
            super(delayTime);
        }
        public void action(){
            addEvent(new Bell(delayTime));
        }
        public String toString(){
            return "Bing!";
        }
    }

    //重启
    public class Restart extends Event{
        private Event[] eventList;
        public Restart(long delayTime, Event[] eventList){
            super(delayTime);
            this.eventList = eventList;
            for(Event e:eventList){
                addEvent(e);  //构造函数首次添加
            }
        }
        public void action(){
            for (Event e: eventList){
                e.start();
                addEvent(e); //调用Restart类的方法时再把内部类eventList保存的数组再次添加到基类数组中，形成死循环
            }
            start();
            addEvent(this); //把自己添加进去，方便下次再添加形成死循环。
        }
        public String toString(){
            return "Restarting system";
        }
    }

    //关机退出,调试用的类
    public static class Terminate extends Event{
        public Terminate(long delayTime){
            super(delayTime);
        }
        public void action(){
            System.exit(0);
        }
        public String toString(){
            return "Terminating";
        }
    }
}
