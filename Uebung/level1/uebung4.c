/*
描述:
    将一个四位数，反向输出。


输入描述：
    一行，输入一个整数n（1000 <= n <= 9999）。
输出描述：
    针对每组输入，反向输出对应四位数。

示列:
    输入：1234
    输出：4321
*/
#include<stdio.h>
// //Loesung1
// int main()
// {
//     int a = 0;
//     scanf("%d", &a);
//     for(int i = 0; i<4; i++)
//     {
//         printf("%d", a%10);
//         a /= 10;
//     }
//     return 0;
// }

int main()
{
    char ch[10];
    scanf("%s", ch);
    for (int i = 3; i >=0; i--)
    {
        printf("%c", ch[i]);
    }
    return 0;
}