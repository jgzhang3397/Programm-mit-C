/*
描述
    问题：一年约有 3.156×10^7 s，要求输入您的年龄，显示该年龄合多少秒。

数据范围： 0 < age <=200

输入描述：
    一行，包括一个整数age
输出描述：
    一行，包含一个整数，输出年龄对应的秒数。
*/
#include<stdio.h>
#include<math.h>
int main()
{
    long int age, second;
    scanf("%ld", &age);
    //second = age * 3.156e7;
    second = age * 3.156 * pow(10, 7);
    printf("%ld", second);
    return 0;
}