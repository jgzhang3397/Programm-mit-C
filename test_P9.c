#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// goto 语句的用法， 示列关机程序
// 
int main()
{
    char input[20] = {0};
 again:
    system("sudo shutdown -s +60");
    printf("请在一分钟之内输入：我是猪，否则电脑将关机！\n 请输入：>");
    scanf("%s", input);
    if(strcmp(input,"我是猪")==0)
    {
        exit(0);
    }
    else
    {
        goto again;
    }
    //Alternative
    // while (1)
    // {
    //     /* code */
    // }
    
    return 0;
}
// //打印9*9乘法表
// //1*1=1
// //2*1=1 2*2=2
// //3*1=3 3*2=6 3*3=9
// //......
// int main()
// {
//     int i = 0;
//     int j = 1;
//     for(i=1; i<=9; i++)
//     {
//         //int j = 1;
//         for(j=1; j<=i; j++)
//         {
//             printf("%d*%d=%-2d ", i, j, i*j);//%2d - 右对其， %-2d 左对其
//         }
//         printf("\n");
//     }
//     return 0;
// }

// //求一个数组的最大值
// int main()
// {
//     int i = 0;
//     int arr[]={-1,0,1,2,3,4,5,6,7,8,9};
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     int max = arr[0];
//     for(i=0; i<sz; i++)
//     {
//         if(arr[i]>=max)
//            max = arr[i];
//     }
//     printf("Max= %d\n", max);
//     return 0;
// }

// //求和
// //1/1-1/2+1/3-1/4+1/5-...+1/99-1/100的和
// int main()
// {
//     int i = 0;
//     double sum = 0.0;
//     int flag = 1;
//     for(i=1; i<=100; i++)
//     {
//         sum += flag*1.0/i;
//         flag = -flag;
//     }
//     printf("Sum = %lf\n", sum); // Fehler Wenn i= 0; Sum = inf ===> sehr gross
//     return 0;
// }

// //判断9出现的次数在0到100之间
// int main()
// {
//     int i = 0;
//     int count = 0;
//     for(i=0; i<100; i++)
//     {
//         if(i%10==9)
//         {
//             printf("%d ",i);
//             count++;
//         }
//         if(i/10==9)//wegen 99 muss if sondern else if verwenden
//         {
//             printf("%d ", i);
//             count++;
//         }
//     }
//     printf("\nCount: %d\n", count);
//     return 0;
// }

// // 求100 - 200 间的素数
// // 素数？
// // 只能被1和其本身整除
// #include <math.h>
// int main()
// {
//     int i = 0;
//     int j = 0;
//     int count = 0;
//     //for(i=100; i<=200; i++)
//     //===Optimierung
//     for(i=101; i<200; i+=2)
//     {
//         int j = 0;
//         // for(j=2; j<i; j++)
//         // {
//         //     if(i%j==0)
//         //     {
//         //         break;
//         //     }
//         // }
//         // if(j==i)
//         // {
//         //     printf("%d ", i);
//         //     count++;
//         // }
//         // ===Optimierung===
//         for(j=2; j<=sqrt(i); j++)
//         {
//             if(i%j==0)
//              break;
//         }
//         if(j>sqrt(i))
//         {
//             printf("%d ", i);
//             count++;
//         }
//     }
//     printf("\nCount: %d\n", count);
//     return 0;
// }

// //求2000年到2100年之间的闰年
// //闰年？
// //1.能被4整除但不被100整除
// //2.能被400整除
// int main()
// {
//     int year = 0;
//     int count = 0;
//     for(year=2000; year<=2100; year++)
//     {
//         // if( year %4==0 && year %100!=0)
//         // {
//         //     printf("%d ",year);
//         //     count ++;
//         // }
//         // else if (year %400==0)
//         // {
//         //     printf("%d ", year);
//         //     count ++;
//         // } 
//         if((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0))
//         {
//             printf("%d ", year);
//             count++;
//         }
//     }
//     printf("\nCount = %d\n", count);  
//     return 0;
// }

// //求两个数的最大公约数
// int main()
// {
//     int m = 0;
//     int n = 0;
//     int r = 0;
//     printf("Bitte geben Sie zwei Value ein:>>>");
//     scanf("%d%d", &m, &n);
//     while (m%n!=0)
//     {
//         r = m%n;
//         m = n;
//         n = r;
//     }
//     printf("最大公约数是：%d\n", n);
//     return 0;
// }

// int main()
// {
//     for (int i = 0; i < 100; i++)
//     {
//         if(i%3==0)
//            printf("Die Value mal als 3 in 100 : %d\n " , i);
//     }
//     return 0;
// }


// int main()
// {
//     int a = 0;
//     int b = 0;
//     int c = 0;
//     printf("Bitte geben Sie drei mal Value ein:>>>");
//     scanf("%d%d%d", &a, &b, &c);
//     if(a<b)
//     {
//         int temp = a;
//         a = b;
//         b = temp;
//     }
//     if(a<c)
//     {
//         int temp = a;
//         a = c;
//         c = temp;
//     }
//     if(b<c)
//     {
//         int temp = b;
//         b = c;
//         c = temp;
//     }
//     printf("Von Groeste zu kleineste ordnen: %d %d %d ", a, b, c);
//     return 0;
// }