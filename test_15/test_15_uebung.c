#include<stdio.h>
// //实现init（）初始化数组全为0
// //printf jeder Vektor darin
// //reverse() 数组元素逆置
// void init(int arr[], int sz)
// {
//     for (int i = 0; i < sz; i++)
//     {
//         arr[i] = 0;
//     }
    
// }
// void my_print(int arr[], int sz)
// {
//     for(int i = 0; i< sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
// void reverse(int arr[], int sz)
// {
//     // for (int i = 0; i < sz; i++)
//     // {
//     //     arr[i]=arr[sz-i];
//     // }  
//     int left = 0;
//     int right = sz -1;
//     while (left<right)
//     {
//         int temp = arr[left];
//         arr[left] = arr[right];
//         arr[right] = temp;
//         left++;
//         right--;
//     }
// }
// int main()
// {
//     int arr[]={1,2,3,4,5,6,7,8,9,10};
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     //init(arr, sz);
//     my_print(arr, sz);
//     reverse(arr, sz);
//     my_print(arr, sz);
//     return 0;
// }

// ////die Inhalt zweies Arrays umtauschen
// int main()
// {
//     int arr1[]={1,3,5,7,9};
//     int arr2[]={2,4,6,8,0};
//     int sz = sizeof(arr1)/sizeof(arr1[0]);
//     int temp =0;
//     for (int i = 0; i < sz; i++)
//     {
//         temp = arr1[i];
//         arr1[i] = arr2[i];
//         arr2[i] = temp;
//     }
//     return 0;
// }

// int main()
// {
//     int arr[]={1,2,3,4,5};
//     short* p = (short*)arr;
//     for (int i = 0; i < 4; i++)
//     {
//         *(p+i) = 0;
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// int main()
// {
//     int a = 0x11223344;
//     char *pc = (char*)&a;//44332211-->00332211
//     *pc = 0;
//     printf("%x\n", a);//0x11223300
// }

// int i;//Globale Variante, == 0
// int main()
// {
//     i--;
//     //-1
//     //10000000000000000000000000000001 --原码
//     //11111111111111111111111111111110 --反码
//     //11111111111111111111111111111111 --补码=反码+1
//     if(i > sizeof(i))// sizeof ist unsigned int immer gross null, so i ist auch unsigned int
//     {
//         printf(">\n");
//     }
//     else
//     {
//         printf("<\n");
//     }
//     return 0;
// }

// // //统计一个数其二进制1的个数
// //Loesung1
// // int count_bit_one(unsigned int n)// immer groesser als null
// // {
// //     int count = 0;
// //     while (n)
// //     {
// //         if(n%2==1)
// //         {
// //             count++;
// //         }
// //         n = n/2;
// //     } 
// //     return count;
// // }
// // Loesung 2
// // int count_bit_one_V2(int n)
// // {
// //     int count = 0;
// //     int i = 0;
// //     for (int i = 0; i < 32; i++)
// //     {
// //         if(((n>>i)&1)==1)
// //         {
// //             count++;
// //         }
// //     }
// //     return count;  
// // }
// //Loesung 3
// //n = 13 .z.B.
// //1101 n
// //1100 n-1
// //n = n&(n-1) == 1100
// //1011 n-1
// //n = n&(n-1) == 1000
// //0111 n-1
// //n = n&(n-1) == 0000
// int count_bit_one_V3(int n)
// {
//     int count = 0;
//     while (n)
//     {
//         n = n & (n-1);
//         count++;
//     }
//     return count;
// }
// int main()
// {
//     int a = 0;
//     printf("Bitte geben Sie eine Value ein:>");
//     scanf("%d", &a);
//     //int count = count_bit_one(a);
//     int count = count_bit_one_V3(a);
//     printf("count = %d\n", count);
//     //-1
//     //10000000000000000000000000000001 --原码
//     //11111111111111111111111111111110 --反码
//     //11111111111111111111111111111111 --补码
//     //00000000000000000000000000000001
//     // count == 32 sein
//     return 0;
// }

// //两个int32位整数m和n的二进制表达中，有多少位bit不同
// int get_diff_bit(int m, int n)
// {
//     int temp = m^n;//相同为0，相异为1
//     int count = 0;
//     //return count_bit_one(temp);
//     while (temp)
//     {
//         temp = temp&(temp-1);
//         count++;
//     }
//     return count;
// }
// int main()
// {
//     int m = 0;
//     int n = 0;
//     scanf("%d%d",&m,&n);
//     int count = get_diff_bit(m,n);
//     printf("count=%d\n", count);
// }

// //获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
// void print(int m)
// {
//     int i = 0;
//     printf("ungerade Zahl\n");
//     for ( i = 30; i >=0; i-=2)
//     {
//         printf("%d ", (m>>i)&1);
//     }
//     printf("\n");
//     printf("gerade Zahl\n");
//     for ( i = 31; i >=1; i-=2)
//     {
//         printf("%d ", (m>>i)&1);
//     }
//     printf("\n");
// }
// int main()
// {
//     int m = 0;
//     scanf("%d", &m);
//     print(m);
//     return 0;
// }

void print(int *p, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d ",*(p+i));
    }
    
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int sz = sizeof(arr)/sizeof(arr[0]);
    print(arr, sz);
    return 0;
}