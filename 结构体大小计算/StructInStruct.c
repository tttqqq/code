#include <stdio.h>
 
struct s1
{  
    int a;    //start 0 字节位置
    double b;    //8
    struct aa  //16
	{  
        int bb;   //16
        double cc;  //24
    }aa;  
    int c;    //32
 }s1;  
 
 struct s2{
    char ch;
    char i;
    struct s{
        char ch1; // 需要另开辟空间
        int j;
    }sub;
    char f;
}s2;

struct s3{
    char ch;
    char i;
    struct s31{
        char ch1;
        double j;
    }sub;
    char f;
}s3;

struct s4{
    char ch; // 0
    char i; // 1
    struct s41{
        char ch1; // 8
        double j; // 16
        int w; // 24
    }sub;
    char f;  //start:32 end:40
}s4;

struct s5{
    char ch;
    int i;
    union{
        char ch1;
        int j;
    };
}s5;

#pragma pack(push, 4)  //指定向4对齐 最大是8
struct s6{
    char ch; // start 0, 占用1个字节，空闲3个字节
    int i; // start 4
    float f; // start 8,占用4个字节
    double d; // start 12, end 20
}s6;
#pragma pack(pop)

#pragma pack(push, 10) //指定向10对齐 成员最大是8, so 8 为对齐方式
struct s7{
    char ch; // 0
    int i; // 内部4 start
    float f; // start 8, 内部后边有空余的4个
    double d; // start 16, end 24
}s7;
#pragma pack(pop)

int main()  
{  
  
   printf("s1: %I64d\n",sizeof(s1));    //40
   printf("s2: %I64d\n",sizeof(s2));    //16
   printf("s3: %I64d\n",sizeof(s3));    //32
   printf("s4: %I64d\n",sizeof(s4));    //40
   printf("s5: %I64d\n",sizeof(s5));    //12
   printf("s6: %I64d\n",sizeof(s6));    //20
   printf("s7: %I64d\n",sizeof(s7));    //24
}  