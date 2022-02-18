#include<stdio.h>
//#include"add.c"
/*
=======C语言预处理===========
翻译环境：test.c ---> test.exe(二进制文件)
运行环境：test.exe ---> ...

//mit terminal
===============翻译环境：test.c ---> test.exe(二进制文件)=============
--> 预编译/预处理 : 文本操作
    gcc -E -demo01.c -> demo01.i   
        1. #include 头文件 的包含
        2. 注释删除：使用空格替换注释
        3. #define 
--> 编译：把c代码 翻译成 汇编代码
    gcc -S demo01.i -> demo01.s(汇编代码)
        1. 语法分析
        2. 词法分析
        3. 语义分析
        4. 符号汇总
--> 汇编：把汇编代码 转换成 二进制指令
     gcc -c demo01.s -> demo01.o(目标文件)


--> 目标文件 经过链接器链接 生成可执行文件 demo01.exe
    链接：
        1. 合并段表
        2. 符号表的合并和符号表的重定位

=====================运行环境：test.exe ---> ...===================
1. 程序必须载入内存中
2. 程序执行开始，调用main函数
3. 开始执行程序代码，stack栈（局部变量/形参）堆（）。。。
4. 终止程序 --> 正常终止/意外终止（断电）



*/
//extern int Add(int a, int b);

int main()
{
    // int a = 10;
    // int b = 20;
    // int c = Add(a, b);
    // printf("%d\n", c);
    int arr[10] = {0};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    return 0;
    
}