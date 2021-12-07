#include <stdio.h>

int main()
{
    // int ch = 0;
    // while ((ch = getchar())!=EOF)//ctrl+z
    // {
    //     putchar(ch);
    // }
    int ret = 0;
    int ch = 0;
    char password[20]={0};
    printf("Bitte geben Sie den Password ein:>>>>");
    scanf("%s", password);// \n = 10 so ret = 10.
    //缓冲区还剩一个‘\n'
    //通过getchar（）读取‘\n'
    //scanf结束标志是空格和回车 wenn password = 123 abc, get error
    //getchar();
    while ((ch = getchar()) != '\n')
    {
        /* code */
        ;
    }
    printf("Bitte bestätigen Sie (Y/N):>>>");
    ret = getchar();
    if(ret == 'Y')
    {

        printf("Alles Klar Vielen Dank!\n");
    }
    else
    {
        printf("Schade...") ;
    }
    return 0;

}