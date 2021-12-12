#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
//-------------Uebung--------------------------
//eingeben password 3mal falsch dann exit(0);
int main()
{
    int i = 0;
    char password[20] = {0}; // password[]
    for ( i = 0; i < 3; i++)
    {
        printf("Bitte geben Sie den Password ein:>>>");
        scanf("%s", password);
        if(strcmp(password,"123456")==0)//== kann nicht vergelichen zwei char, soll 'strcmp' verwenden
        {
            printf("Password korrect!\n");
            break;
        }
        else
        {
            printf("Password falsch!!!\n");
        }
    }
    if(i==3)
    {
        printf("falsch eingeben gesperrt!\n");
    }
    return 0;
    
}

// int main()
// {
// //Willkommen zu mir!!!
// //####################
// //W##################!
// //Wi################!!
// //......
// //Willkommen zu mir!!!
// // z.B.
// //Char arr[] = "abc"
// //[a b c \n]
// // 0 1 2  3
// // Breite = 4-2
// // Linux - gcc - #include <unistd.h> -- sheep(s)
// // VC    - #include <windows.h> -- Sheep(ms)
//   char arr1[] = "Willkommen zu mir!!!";
//   char arr2[] = "####################";
//   int left = 0;
//   //int right = sizeof(arr1)/sizeof(arr1[0])-2;
//   int right = strlen(arr1)-1;
//   while (left<=right)
//   {
//       arr2[left]=arr1[left];
//       arr2[right]=arr1[right];
//       printf("%s\n",arr2);
//       sleep(1);//1s
//       system('clear');// clean the screen ====>funktiniert nicht!!???
//       left++;
//       right--;
//   }
//   return 0;
// }

// //Optimierung
// int main()
// {
//     int arry[]={1,2,3,4,5,6,7,8,9,10};
//     int sz = sizeof(arry)/sizeof(arry[0]);
//     int left = 0;
//     int right = sz -1;
//     int k = 0;
//     printf("Bitte geben Sie die Value ein:>>>");
//     scanf("%d",&k);
//     while (left <= right)
//     {
//         int mid = (left + right)/2;
//         if (arry[mid]>k)
//         {
//             right = mid -1;
//         }
//         else if (arry[mid]<k)
//         {
//             left = mid +1;
//         }
//         else
//         {
//             printf("Habe gefunden legt auf Nr.: %d", mid);
//             break;
//         }
//     }
//     return 0;  
// }

//在一个有序的数组中通过遍历找到一个数value
// int main()
// {
//     int arry[] = {1,2,3,4,5,6,7,8,9,10};
//     int sz = sizeof(arry)/sizeof(arry[0]);
//     int k = 17;
//     int i = 0;
//     for(i=0; i<sz; i++)
//     {
//         if(k == arry[i])
//         {
//             printf("Hab gefunden %d\n", i);
//             break;
//         }
//     }
//     if(i == sz)
//     {
//         printf("Hab nicht gefunden\n");
//     }
// }

// //brechnen 10! + 9! + ..+1!
// //Optimal
// int main()
// {
//     int n = 0;
//     int erg = 1;
//     int sum = 0;
//     for(n=1; n<=4; n++)
//     {
//         erg = erg * n;
//         sum = sum + erg;
//     }  
//     printf("Sum = %d\n", sum);
//     return 0;
// }
// int main()
// {
//     int i = 0;
//     int erg = 1;
//     int n = 0;
//     int sum = 0;
//     for (n=1; n<=3; n++)
//     {
//        erg = 1;
//        for(i=1; i<=n; i++)
//        {
//           erg = erg * i;
//        }
//        sum = sum + erg;
//     }
//     printf("Sum = %d\n", sum);
//     return 0;
// }

// //计算n的阶乘
// int main()
// {
//     int erg = 1;
//     int n = 0;
//     int i = 0;
//     printf("Bitte geben Sie n ein:>>>");
//     scanf("%d", &n);
//     for(i = 1; i<=n; i++)
//     {
//         erg = erg * i;
//     }
//     printf("Das Ergebnis: %d\n", erg);
//     return 0;
// }

// int main()
// {
//     int i = 0;
//     do
//     {
//         i++;
//         if(i==5)
//            break;
//            //continue;
//         printf("hehe %d\n", i);
//     } while (i<10);
    
// }

// int main()
// {
//     int i=0 , j = 0;
//     for(i=0,j=0;j=0;i++,j++)//j=0 ist keine Entscheidung, deswegen 0 mal Kreislauf
//     {
//         j++;
//     }
//     return 0;

// }

// int main()
// {
//     //Variante1
//     // for(;;)
//     // {
//     //     printf("Hehe\n");
//     // }
//     //Variante2
//     int i, j;
//     for (i = 0, j = 0; i < 2 && j<5; i++, ++j)
//     {
//         printf("Hehe\n");
//     }
    
//     // for(int i = 0; i<10; i++)
//     // {
//     //     for(int j = 0; j<10; j++)
//     //     {
//     //         printf("hehe \n");
//     //     }
//     // }
//     // int i = 0;
//     // // 初始化； 判断 ； 调整
//     // for(i=1; i<=10 ; i++)
//     // {
//     //     if (i==5)
//     //     {
//     //         //break;
//     //         continue;
//     //     }
//     //     printf("%d ", i);
//     // }
//     // int arr[10]={1,2,3,4,5,6,7,8,9,10};
//     // for(int i =0; i<10; i++)
//     // {
//     //     printf("%d ",arr[i]);
//     // }
//     return 0;
// }

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