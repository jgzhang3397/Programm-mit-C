#include <stdio.h>
int main()
{
    //Variante1
    // for(;;)
    // {
    //     printf("Hehe\n");
    // }
    //Variante2
    int i, j;
    for (i = 0, j = 0; i < 2 && j<5; i++, ++j)
    {
        printf("Hehe\n");
    }
    
    // for(int i = 0; i<10; i++)
    // {
    //     for(int j = 0; j<10; j++)
    //     {
    //         printf("hehe \n");
    //     }
    // }
    // int i = 0;
    // // 初始化； 判断 ； 调整
    // for(i=1; i<=10 ; i++)
    // {
    //     if (i==5)
    //     {
    //         //break;
    //         continue;
    //     }
    //     printf("%d ", i);
    // }
    // int arr[10]={1,2,3,4,5,6,7,8,9,10};
    // for(int i =0; i<10; i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    return 0;
}

// int main()
// {
//     int ch = 0;
//     while ((ch=getchar()) != EOF)
//     {
//         if(ch<'0' || ch>'9')//nur 0 ~ 9 ausgeben
//            continue;
//         putchar(ch);
//     }
    
// }

// int main()
// {
//     // int ch = 0;
//     // while ((ch = getchar())!=EOF)//ctrl+z
//     // {
//     //     putchar(ch);
//     // }
//     int ret = 0;
//     int ch = 0;
//     char password[20]={0};
//     printf("Bitte geben Sie den Password ein:>>>>");
//     scanf("%s", password);// \n = 10 so ret = 10.
//     //缓冲区还剩一个‘\n'
//     //通过getchar（）读取‘\n'
//     //scanf结束标志是空格和回车 wenn password = 123 abc, get error
//     //getchar();
//     while ((ch = getchar()) != '\n')
//     {
//         /* code */
//         ;
//     }
//     printf("Bitte bestätigen Sie (Y/N):>>>");
//     ret = getchar();
//     if(ret == 'Y')
//     {

//         printf("Alles Klar Vielen Dank!\n");
//     }
//     else
//     {
//         printf("Schade...") ;
//     }
//     return 0;

// }