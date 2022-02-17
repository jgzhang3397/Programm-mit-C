#include<stdio.h>
#pragma pack(4)/* 设置4字节对齐 */
/*
1. 计算结构体的大小
*/


typedef struct 
{
    int a;//0-3 4byte
    char b;//4  1byte
    //5
    short c;//6-7 2byte 默认对齐数4，
    short d;//8-9 2byte
    //sum = 10byte
    //结构体总大小必须是最大字节的整数倍 -- 12byte
}AA_t;

//================题目要求默认对齐数是4 64位long字节数是8=======================
typedef struct 
{
    int a;//0-3  
    short b;//4-5   
    //6-7   
    int c;//8-11
    char d;//12
    //sum = 13 --4-> 16
}aa;

struct B
{
    int a;//0-3
    short b;//4-5
    char c;//6-7
    int d;//8-11
    //sum = 12 --4-> 12
};

struct tagTest1
{
    short a;//0-1
    char d;//2
    //3
    long b;//4-11
    long c;//12-19
    //sum - 20 --4-> 20
};

struct tagTest2
{
    long b;//0-7
    short c;//8-9
    char d;//10
    //11
    long a;//12-19
    //sum - 20 --4-> 20
};

struct tagTest3
{
    short c;//0-1
    //2-3
    long b;//4-11
    char d;//12
    //13-15
    long a;//16-23
    //sum - 24 --4-> 24
};

void Test01()
{
    printf("%d %d %d\n", sizeof(struct tagTest1), sizeof(struct tagTest2), sizeof(struct tagTest3));
}

int main()
{
    printf("%d\n", sizeof(AA_t));
    printf("%d\n", sizeof(aa));
    printf("%d\n", sizeof(struct B));
    Test01();
    return 0;
}
#pragma pack()
