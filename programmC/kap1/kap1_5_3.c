#include<stdio.h>

//统计输入的字符个数
void demo01()
{
    long c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
    {
        if(c == '\n')
            break;
        else
            ++nl;
    }
    printf("%ld\n", nl);
}

//统计行数
void demo02()
{
    long c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
    {
        if(c == '\n')
            ++nl;
        else if(c == ' ')
        {
            ++nl;
            break;
        }     
    }
    printf("%ld\n", nl);
}
int main()
{
    demo02();
    return 0;
}