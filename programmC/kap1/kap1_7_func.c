#include<stdio.h>

//测试power函数
int power(int x, int y);
int power_v2(int m, int n);

int main()
{
    int i;
    for(i=0; i<10; ++i)
    {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
        printf("%d %d %d\n", i, power_v2(2, i), power_v2(-3, i));
    }
    return 0;
}

//power函数， 求base的 n次
int power(int base, int n)
{
    int i;
    int sum = 1;
    for(i = 1; i<=n; ++i)
    {
        sum = sum*base;
    }
    return sum;
}

//power函数 version2
int power_v2(int base, int n)
{
    int sum = 1;
    for(n=n; n>0; --n)
        sum *= base;
    return sum;
}