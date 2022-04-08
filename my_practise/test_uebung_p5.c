/*
题目：
    猜名次
        A: B->2, A ->3;
        B: B->2, E ->4;
        C: C->1, D ->2;
        D: C->5, D ->3;
        E: E->4, A ->1;
    每位选手只说对了一半，求各自名次
*/
// #include<stdio.h>
// int main()
// {
//     int a,b,c,d,e;
//     for(a = 1; a<=5; a++)
//     {
//         for(b = 1; b<=5; b++)
//         {
//             for(c = 1; c<=5; c++)
//             {
//                 for(d = 1; d<=5; d++)
//                 {
//                     for(e = 1; e<=5; e++)
//                     {
//                         if( ((b==2)+(a==3)==1)&&
//                             ((b==2)+(e==4)==1)&&
//                             ((c==1)+(d==2)==1)&&
//                             ((c==5)+(d==3)==1)&&
//                             ((e==4)+(a==1)==1)
//                           )
//                           {
//                               if(a*b*c*d*e == 120)
//                               {
//                                   printf("A=%d, B=%d, C=%d, D=%d, E=%d\n", a,b,c,d,e);
//                               }
//                           }
//                     }
//                 }
//             }
//         }
//     }
//     return 0;
// }

// #include<stdlib.h>

// int main()
// {
//     //申请空间
//     int *p = (int*)malloc(10*sizeof(int));
//     //使用空间
//     //****
//     //释放空间
//     free(p);
//     p = NULL; //当使用free释放掉指针内容后，指针变量的值应该手动设置为null
//     return 0;
// }

#include<stdio.h>
int main()
{
    char str1[] = "hello";
    char str2[] = "hello";
    char *str3 = "hello";
    char *str4 = "hello";

    if(str1 == str2)//各自数组的首元素地址不同，只有首元素内容相同
        printf("str1 & str2 same\n");
    else
        printf("str1 & str2 not same\n");
    if(str3 == str4)//数组的首元素地址分别存放在str3 和 str4 中
        printf("str3 & str4 same\n");
    else
        printf("str3 & str4 not same\n");
    return 0;
}