#include<stdio.h>

#define MAX 100 //定义符号
#define STR "hello world"
#define reg register //为 register 关键字 创建一个简短的名字
#define do_forever for(;;) //用更形象的符号来替换一种实现
#define CASE break:case //在写case语句的时候自动把break写上
//如果定义的stuff过长，可以分成几行写，除最后一行外，每行后面加一个反斜杠
#define DEBUG_PRINT printf("file:%s\t line:%d\t \
                            date:%s\t time:%s\n", \
                            __FILE__, __LINE__, \
                            __DATE__, __TIME__)

//定义宏 : 一定要多加括号()
#define SQUARE(X) X*X 
#define SQUARE_1(X) (X)*(X)
#define DOUBLE(X) ((X)+(X))

//# 和 ##
#define PRINT(X) printf("The Value of " #X " is %d\n", X) // #X ==> "X"

#define CAT(X, Y) X##Y
/*
预定义符号：
    _FILE_ //进行编译的源文件
    _LINE_ //文件当前的行号
    _DATE_ //文件被编译的日期
    _TIME_ //文件被编译的时间
    _FUNCTION_
    _STDC_ //如果编译器遵循ANSI-C，其值为1，否则为定义

预处理指令：
    #define
    #include
    #pragma pack(4)
    #pragma
    #if
    #endif
    #ifdef
    #line
*/

void Test01()
{
    printf("%s\n", __FILE__);
    printf("%d\n", __LINE__);
    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);
    printf("%d\n", __STDC__);
}

void Test02()
{
    //写日志文件
    int arr[10] = {0};
    int len = sizeof(arr)/sizeof(arr[0]);
    FILE* pf = fopen("/Users/jingangzhang/workspace/Programm-mit-C/test_23/part2/log.txt","w");
    for (int i = 0; i <len; i++)
    {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    printf("\n");
    fprintf(pf, "file: %s line: %d date: %s time: %s\n",
            __FILE__, __LINE__, __DATE__, __TIME__);
    DEBUG_PRINT;
    fclose(pf);
    pf = NULL;
}

void Test03()
{
    printf("%d\n", MAX);
    printf("%s\n", STR);
    //do_forever;//死循环
    int ret = SQUARE(5);
    printf("%d\n", ret);
    ret = SQUARE(5 + 1);// 宏 是完成替换的，不是传参的
    printf("%d\n", ret);//11 == 5+1*5+1

    ret = SQUARE_1(5 + 1);// 宏 是完成替换的，不是传参的
    printf("%d\n", ret);//36 

    int num = 10;
    int sum = num * DOUBLE(5);
    printf("%d\n", sum);//100
}

void Print()
{
    int a = 10;
    int b = 20;
    PRINT(a);
    PRINT(b);
}

void Test04()
{
    int value01 = 2022;
    printf("%d\n", CAT(value, 01));
    printf("%d\n", value01);//value01 ==> value##01
}

int main()
{
    //Test01();
    //Test02();
    //Test03();
    //Print();
    //Test04();
    return 0;
}