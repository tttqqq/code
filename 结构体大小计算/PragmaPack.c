#include<stdio.h>

struct s
{
    char m0;
    short m1;
    double m2;
    int m3;
    char m4;
}x;

// #pragma pack(1) //这里n的取值可以是1、2、4、8、16（2的n次幂），如果不是这些数，就按默认的方式处理对齐
#pragma pack(push, 1)
struct s1
{
    char m0;
    short m1;
    double m2;
    int m3;
    char m4;
}x1;
// #pragma pack() // 取消自定义对齐，恢复到 编译器默认 对齐
#pragma pack(pop) // 取消自定义对齐，恢复到 上一次的 对齐

#pragma pack(push, 2)
struct s2
{
    char m0;
    short m1;
    double m2;
    int m3;
    char m4;
}x2;
#pragma pack(pop) // 取消自定义对齐，恢复到 上一次的 对齐

#pragma pack(push, 4)
struct s3
{
    char m0;
    short m1;
    double m2;
    int m3;
    char m4;
}x3;
#pragma pack(pop) // 取消自定义对齐，恢复到 上一次的 对齐

#pragma pack(push, 8)
struct s4
{
    char m0; // start 0 字节位置
    short m1; // 内部start 2 ,占用2个字节，内部后边的4个空闲
    double m2; // start 8
    int m3;  // start 16
    char m4; // 内部start 20, 占用1个，空闲3个，end 24
}x4;
#pragma pack(pop) // 取消自定义对齐，恢复到 上一次的 对齐

#pragma pack(push, 16) //指定向16对齐 成员最大是8, so 8 为对齐方式
struct s5
{
    char m0; // start 0
    short m1; // 内部start 2, 占用2个，空闲4个
    double m2; // start8
    int m3; // start 16
    char m4;  // 内部start20，占用1个字节，空闲3个, end 24
}x5;
#pragma pack(pop) // 取消自定义对齐，恢复到 上一次的 对齐

int main()
{
    printf("x: %I64u\n",sizeof(x)); // 24

    printf("x1: %I64u\n",sizeof(x1)); // 16
    printf("x2: %I64u\n",sizeof(x2)); // 18
    printf("x3: %I64u\n",sizeof(x3)); // 20
    printf("x4: %I64u\n",sizeof(x4)); //pack24
    printf("x5: %I64u\n",sizeof(x5)); //pack24 还是以成员最大的为计算
    return 0;
}