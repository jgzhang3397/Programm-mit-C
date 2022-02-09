#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

void GetMemory(char **p, int num)
{
    *p = (char *)malloc(num);
}

void Test01(void)
{
    char *str = NULL;
    GetMemory(&str, 100);
    strcpy(str, "hello");
    printf(str);//hello, 但是存在内存泄漏
    //改进
    free(str);
    str = NULL;
}

void Test02(void)
{
    char *str = (char *)malloc(100);
    strcpy(str, "hello");
    free(str);//str访问的内存空间被释放，找不到“hello”，但是str不是null指针
    if(str != NULL)
    {
        strcpy(str, "world");
        printf(str);//world
    }
}

int main()
{
    //Test01();
    Test02();
    return 0;
}