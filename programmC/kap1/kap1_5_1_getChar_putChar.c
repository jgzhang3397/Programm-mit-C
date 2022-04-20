#include<stdio.h>

void demo01()
{
    //c的类型是int 而不是char 原因
    //int的范围足够放下任何字符
    //char只能放255个字符
    int c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
}

void demo02()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
    
}

//getchar()!=EOF == 1 or 0 ?
void pre_1_6()
{
    printf("%d\n", (getchar()!=EOF));
}

//EOF == ?
void pre_1_7()
{
    //printf("%d\n", EOF);
    printf("%d\n", (getchar()==EOF));
}

int main()
{
    //demo01();
    //demo02();
    //pre_1_6();
    //pre_1_7();
    kap_1_5_2();
    return 0;
}