//==========数据在内存中的存储==============
/*
C语言类型
    内置类型： char short int long long long float double
        整型家族：
            char
                unsigned char 0 - 255
                signed char -128 - 127
            short
                unsigned short[int]
                signed short [int]
            int 
                unsigned int
                signed int
            long
                unsigned long
                signed long
        浮点型家族：
            float
            double
    自定义构造类型：
        数组类型 int arr[10]; int[10]
        结构体类型 struct
        枚举类型 enum
        联合类型 union
    指针类型：
        int* pi;
        char* pc;
        float* pf;
        void* pv;
    空类型：
        void 表示空类型 就是无类型
        通常应用于函数的返回类型，函数的参数，指针类型
*/
//=============整型在内存中的存储=========
/*
整型（整数）：数据存放在内存的是补码
    原码 反码 补码
        有符号位， 正数：原反补相同。负数：0为负 1为正
        无符号位： 原反补相同
大端存储模式：倒着存 数据的低位保存内存高地址中，数据的高位保存在内存的低地址
小端存储模式：正着存 数据的高位保存内存低地址中，数据的低位保存在内存的高地址
*/
#include <stdio.h>

/*
Test01():
整型（整数）：数据存放在内存的是补码
    原码 反码 补码
        有符号位， 正数：原反补相同。负数：0为负 1为正
        无符号位： 原反补相同  
*/
void Test01()
{
    int a = 20;
    //000000000000000000000000 0001 0100 -原码
    //000000000000000000000000 0001 0100 -反码
    //000000000000000000000000 0001 0100 -补码
    //0x000000 14

    int b = -10;
    //1000 0000 0000 0000 0000 0000 0000 1010 -原码
    //1111 1111 1111 1111 1111 1111 1111k 0101 -反码
    //1111 1111 1111 1111 1111 1111 1111 0110 -补码
    //0xfffffff6

    int c = 1 - 1;//0
    // 1 + (-1)
    //00000000000000000000000000000001
    //11111111111111111111111111111111
    //1 00000000000000000000000000000000 -- 1是的第33位 丢去

    // 1
    //00000000000000000000000000000001 - 补码

    // -1
    //10000000000000000000000000000001 - 原码
    //11111111111111111111111111111110 - 反码
    //11111111111111111111111111111111 - 补码

    int d = 0x11223344;
    printf("%p\n", &d);//0x7ffeefbff30c
}

/*
Test02():
    判断当前机器的字节序
    return 1 ==> 小端
    return 0 ==> 大端
*/

int check_sys_V1()
{
    int a = 1;
    char* pc = (char*) &a;
    if(*pc == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int check_sys_V2()
{
    int a = 1;
    char* pc = (char*) &a;
    // *pc ==1 return 1, ==0, return 0
    return *pc;
}

int check_sys_V3()
{
    int a = 1;
    return *(char*) &a;
}

void Test02()
{
    int ret = check_sys_V3();
    if(ret == 1)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }
}

/*
Test03():
    指针类型的意义
    决定了能访问几个字节
*/
void Test03()
{
    int a = 0x11223344;
    int b = 0x11223344;
    short *ps = &a;
    *ps = 0;
    printf("%x\n", a);
    char *pc = &b;
    *pc = 0;
    printf("%x\n", b);
}

void Test04()
{
    char a = -1;//-1的补码全1
    //10000001 -原
    //11111110 -反
    //11111111 -补

    signed char b = -1;
    //same with a --> -1

    unsigned char c = -1;
    //11111111
    //00000000000000000000000011111111
    //255
    printf("a=%d, b=%d, c=%d\n", a, b, c);//char-->int 整型提升 a=-1, b=-1, c=255
}

/*
Test05():
    char -128~127 // im char 128 = 127+1 im Kreis gleich = -128
    unsigned char 0~255 
*/
void Test05()
{
    char a = -128;
    char b = 128;
    //10000000000000000000000010000000 == a
    //11111111111111111111111101111111
    //11111111111111111111111110000000-->补码
    //10000000
    //11111111111111111111111110000000-->整型提升，补码
    //unsigned char 无符号位 原反补相同
    //11111111111111111111111110000000
    printf("%u\n", a);//4294967168
    //%d 打印十进制的有符号数字
    //%u 打印十进制的无符号数字
    printf("%u\n", b);//4294967168
}

void Test06()
{
    //-20
    //100000000000000000000000000010100
    //111111111111111111111111111101011
    //111111111111111111111111111101100 --补码1
    int i = -20;
    //10 正数 原反补相同
    //000000000000000000000000000001010 --补码2
    //补码1 + 补码2
    //111111111111111111111111111110110 --结果
    //111111111111111111111111111110101 --结果反码
    //100000000000000000000000000001010 --结果原码
    unsigned int j = 10;

    printf("%d\n", i+j);//-10
}

/*
sleep 用法
*/
#include<unistd.h>
void Test07()
{
    unsigned int i;
    for(i = 9; i>=0; i--)
    {
        printf("%u\n", i);
        sleep(1);//1s
    }
}

/*
Test08():

*/
#include<string.h>
void Test08()
{
    char a[1000];
    int i;
    for ( i = 0; i < 1000; i++)
    {
        a[i] = -1 -i;//-1， -2， -3， ... -128, -129, ... , -1000
                     //-1， -2， -3， ... -128, 127, 126, ... , 2, 1, 0 = 255
    }
    printf("%lu\n", strlen(a));//255
}

unsigned char i = 0; //0~255,条件恒成立，死循环；
void Test09()
{
    for ( i = 0; i <=255; i++)
    {
        printf("Hello world\n");
    }
}

void Test10()
{
    double d = 1E10; // 1^10
    printf("%.1lf\n", d);
}

void Test11()
{
    int n =9;
    float *pFloat = (float *)&n;
    printf("n = %d\n", n);//9
    printf("*pFloat = %f\n", *pFloat);//0.000000

    *pFloat = 9.0;
    printf("n = %d\n", n);
    printf("*pFloat = %f\n", *pFloat);//9.000000
}

int main()
{
    //Test01();
    //Test02();
    //Test03();
    //Test04();
    //Test05();
    //Test06();
    //Test07();
    //Test08();
    //Test09();
    //Test10();
    Test11();
    return 0;
}
