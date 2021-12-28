/*
转换以下ASCII码为对应字符并输出他们。
73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116 , 33
*/
#include<stdio.h>
int main()
{
    char ch[] = {73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33};
    int i = 0;
    int sz = sizeof(ch)/sizeof(ch[0]);
    for (i = 0; i < sz; i++)
    {
        printf("%c", ch[i]);
    }
    printf("\n");
    return 0;
}