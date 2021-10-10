#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_LEN  10

int ShowArray(int *pArray, int len)
{
    if (pArray == NULL || len < 1){
        return -1;
    }

    for(int i = 0; i < len; i++) {
        printf("element: %d\n", pArray[i]);
    }

    return 0;
}

int PopoSort(int *pArray, int len)
{
    if (pArray == NULL) {
        return -1;
    }

    for(int i = 0; i < len - 1; i++) {
        for(int j = i + 1; j < len; j++) {
#if 1
            if (pArray[i] > pArray[j]) {
                int temp = pArray[i];
                pArray[i] = pArray[j];
                pArray[j] = temp;
            }
#else
            if (*(pArray + i) < *(pArray + j)) {
                int temp = *(pArray + i);
                *(pArray + i) = *(pArray + j);
                *(pArray + j) = temp;
            }
#endif
        }        
    }

    return 0;
}

int main(void)
{
    int array[ARRAY_LEN] = {0};

    srand((unsigned int)time(0));

    for (int i = 0; i < ARRAY_LEN; i++) {
        array[i] = rand() % 100 + 1;
    }

    printf("The origin Array is as follows:\n");
    ShowArray(array, ARRAY_LEN);

    PopoSort(array, ARRAY_LEN);
    printf("The popp Array is as follows:\n");
    ShowArray(array, ARRAY_LEN);
    return 0;
}