#include<stdio.h>
/*
Test01():

枚举类型的定义：
    就是一一列举

优点；
    1. 增加代码的可读性和可维护性
    2. 和#define定义的标识符比较枚举有类型检查，更加严谨
    3. 防止了命名污染(封装)
    4. 便于调试
    5. 使用方便， 一次可以定义多个常量

*/

enum Day //星期
{
    Mon,
    Tues,
    Wed,
    Thur,
    Fri,
    Sat,
    Sun
};

enum Sex
{
    Male,//0
    Female,//1
    Secret //2
};

enum Color
{
    //枚举的可能取值-常量；不可被修改
    RED = 2,
    GREEN = 8,
    BLUE = 10
};

void Test01()
{
    enum Sex s = Male;
    s = Female;

    enum Day d = Mon;
    printf("%d %d %d\n", Male, Female, Secret);//0 1 2
    printf("%d %d %d\n", RED, GREEN, BLUE);//2 8 10
}

/*
Test02():
    联合（共同体）
    联合类型的定义：
        联合也是一种特殊的自定义类型 这种类型定义的变量包含一系列的成员，特征是这些成员共用同一块空间
        （所以联合也叫共用体）。
    特点：
        联合的成员是共用同一块内存空间的，这样一个联合变量的大小，至少是最大成员的大小
        当最大成员大小不是最大对齐数的整数倍是，就要对齐到最大对齐数的整数倍
*/
union un
{
    char c;
    int i;
};

void Test02()
{
    union un u;
    printf("%lu\n", sizeof(u));//4

    //共用同一块空间
    printf("%p\n", &u);    //0x7ffeefbff3b8
    printf("%p\n", &(u.c));//0x7ffeefbff3b8
    printf("%p\n", &(u.i));//0x7ffeefbff3b8
}

/*
Test03():

*/

int check_sys()
{
    //====pointer===
    int a = 1;//0x00 00 00 01
    return *(char*)&a;//取a的地址强转char* 字符指针 然后*解引用取出一个字节

    //=====union====
    // union uni
    // {
    //     char c;
    //     int i;
    // }u;
    // u.i = 1;
    // return u.c;//返回1表示小端，返回0表示大端

}

void Test03()
{
    int ret = check_sys();
    if(1 == ret)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }
    //int a = 0x11223344;
    //低地址---->高地址
    //...[11][22][33][44]... 大端字节序存储
    //...[44][33][22][11]... 小端字节序存储
}

int main()
{
    //Test01();
    //Test02();
    Test03();
    return 0;
}