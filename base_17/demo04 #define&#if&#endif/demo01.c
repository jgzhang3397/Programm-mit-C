#include<stdio.h>
//#include"test.h"
#include"add.h"
#include"add.c"

/*
Test01: 
        命令行定义: Terminal 给 SZ 具体值
            命令：
                gcc -demo01.c -D sz=10

Test04:
        多分支条件编译：
            #if 常量表达式
                ..
            #elif
                ..
            #else
                ..
            #endif

Test05:
        判断是否被定义：
            #if defined(symbol)
            #ifdef symbol

            #if !defined(symbol)
            #ifndef symbol


嵌套指令：
    #if defined(OS_UNIX)

        #ifdef OPTION1
            unix_version_option01();
        #endif

        #ifdef OPTION2
            unix_version_option02();
        #endif

    #elif defined(OS_MSDOS)

        #ifdef OPTION2
            msdos_version_option02();
        #endif

    #endif


#include: 
    库文件包含：< >
    本地文件包含：" "

Test06:
        #include自定义函数


*/

// void Test01()
// {
//     int arr[SZ] = {0};
//     for (int i = 0; i < SZ; i++)
//     {
//         arr[i] = i;
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

#define _DEBUG_

/*
Test02/03:
        条件编译指令：
            #if 常量表达式(1 = true, 0 = false)
            #endif

            #define _DEBUG_
            #ifdef _DEBUG_
                    ...
            #endif
*/
void Test02()
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[10]); i++)
    {
        arr[i] = 0;

#ifdef _DEBUG_
        printf("%d ", arr[i]);
#endif

    }
    
}

void Test03()
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[10]); i++)
    {
        arr[i] = 0;

#if 0
        printf("%d ", arr[i]);
#endif
    }
}

void Test04()
{

#if 1==1
    printf("1 == 1\n");
#elif 1==2
    printf("1 == 2\n");
#else 
    printf("1 ~= 1\n");
#endif

}

void Test05()
{
//==========================
#if defined(_DEBUG_)
    printf("debug is defined\n");
#endif

#ifdef _DEBUG_
    printf("debug is defined\n");
#endif
//==========================
#if !defined _DEBUG_
    printf("debug isn't defined\n");
#endif

#ifndef _DEBUG_
    printf("debug isn't defined\n");
#endif
}

void Test06()
{
    int a = 10;
    int b = 20;
    int c = Add(10, 20);
    printf("%d\n", c);
}

int main()
{
    //Test01();
    Test02();
    //Test03();
    //Test04();
    //Test05();
    //Test06();
    return 0;
}