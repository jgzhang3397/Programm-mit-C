/*
描述:
    给定一个浮点数，要求得到该浮点数的个位数。

数据范围： 
    0 <= n <= 200
输入描述：
    一行，包括一个浮点数。
输出描述：
    一行，包含一个整数，为输入浮点数对应的个位数。
*/
#include<stdio.h>
int main()
{
    float a;
    scanf("%f", &a);
    int n = (int)a;
    if(0<= n && n <= 200)
    {
        printf("%d\n", n%10);
    }
    else
    {
        printf("Error\n");
    }
    return 0;
}