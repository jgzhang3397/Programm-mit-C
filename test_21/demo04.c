#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

char *GetMemory(void)
{
    char p[] = "hello world";
    return p;//返回栈空间的地址的问题 p的生命周期只在函数体内
}

void Test01(void)
{
    char *str = NULL;
    str = GetMemory();
    printf(str);//随机值
}

int main()
{
    Test01();
    return 0;
}