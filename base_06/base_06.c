#include<stdio.h>
#include"add.h"
#include"add.c"

void Test01()
{
    //the total number of characters written is returned. prinf()
    int a = printf("%d", 56);//2
    int b = printf("%d", a);//1
    //printf("%d\n", a);
    printf("%d\n", b);//5621
}

void Test02()
{
    int a = 10;
    int b = 20;
    int sum = Add(a, b);
    printf("%d ", sum);
}

int main()
{
    //Test01();
    Test02();
    return 0;
}