#include<stdio.h>

// int Add(int a, int b)
// {
//     return a+b;
// }
// int main()
// {
//     int a = 10;
//     int b = 20;
//     int sum = Add(a, b);
//     printf("sum: %d\n", sum);
//     return 0;
// }
#include<string.h>
// int main()
// {
//     //strcpy string copy
//     char arr1[]="Hallo!";
//     char arr2[20]="**********";
//                 // Hallo!\0, '\0'bedeutet beenden
//     strcpy(arr2, arr1);
//     printf("%s\n", arr2);
//     return 0;
// }
// int main()
// {
//     char arr[]="Hello World!\n";
//     memset(arr, '*', 5);//memset, memroy setting
//     printf("%s\n", arr);
//     return 0;
// }
// int get_Max(int x, int y)
// {
//     if(x>y)
//        return x;
//     else 
//        return y;
// }
// int main()
// {
//     int a = 10;
//     int b = 20;
//     printf("Bitte geben Sie zwei Value ein:>");
//     scanf("%d%d", &a, &b);
//     int max = get_Max(a, b);
//     printf("max: %d\n", max);
//     return 0;
// }
//die Value von a und b umtauschen
// //Es geht nicht
// void Swap1(int x, int y)
// {
//     int temp = 0;
//     temp = x;
//     x = y;
//     y = temp;
// }
// void Swap2(int* pa, int* pb)
// {
//     int temp = 0;
//     temp = *pa;
//     *pa = *pb;
//     *pb = temp;
// }
// int main()
// {
//     int a = 10;
//     int b = 20;
//     printf("a=%d b=%d\n",a,b);
//     //Swap1(a, b);
//     Swap2(&a, &b);
//     printf("a=%d b=%d\n",a,b);
//     return 0;
// }
// //输出100～200之间的素数
// #include<math.h>
// int is_prime_num(int n)
// {
//     // int m = 0;
//     // for(m=2; m<=sqrt(n); m++)
//     // {
//     //     if(n%m == 0)
//     //        break;
//     // }
//     // if(m>sqrt(n))
//     //     return 1;
//     // else
//     //     return 0;
//     //Optimeriung
//     //2->n-1
//     int j = 2;
//     for(j=2; j<=sqrt(n); j++)
//     {
//         if(n%j == 0)
//            return 0;
//     }
//     return 1;
// }
// int main()
// {
//     int i = 0;
//     for(i=100;  i<=200; i++)
//     {
//         if(is_prime_num(i)==1)
//         {
//             printf("%d ", i);
//         }
//     }
//     return 0;
// }
// //判断2000～2100年之间的闰年并输出
// int is_leap_year(int i)
// {
//     if((i%4==0 && i%100!=0)||i%400==0)
//        return 1;
//     else
//        return 0;
// }
// int main()
// {
//     int year = 2000;
//     for(year=2000; year<=2100; year++)
//     {
//         if(is_leap_year(year)==1)
//         {
//             printf("%d ", year);
//         }
//     }
//     return 0;
// }
// //二分查找
// //在一个有序的序列中查找一个数，找到了返回其下标，没找到返回-1
//                       //arr是一个指针
// int binary_search(int arr[], int k, int sz)
// {
//     int left = 0;
//     int right = sz -1;
//     while (left<=right)
//     {
//         int mid = (left + right)-1;
//         if(arr[mid]< k)
//         {
//             left = mid + 1;
//         }
//         else if(arr[mid]> k)
//         {
//             right = mid -1;
//         }
//         else
//         {
//             return mid;
//         }
//     }
//     return -1;  
// }
// int main()
// {
//     int arr[]={1,2,3,4,5,6,7,8,9,0};
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     int k = 0;
//     printf("Bitte geben Sie eine Value ein:>");
//     scanf("%d", &k);
//     //int k = 7;               //arr传到函数的是die Addresse von arr[0]
//     int result = binary_search(arr, k, sz);
//     if(result == -1)
//     {
//         printf("Nicht gefunden\n");
//     }
//     else
//     {
//         printf("%d ", result);
//     }
//     return 0;
// }
//---------
void Add(int* p)
{
    (*p)++;
}
int main()
{
    int num = 0;
    printf("%d ", num);
    Add(&num);
    printf("%d ", num);
    Add(&num);
    printf("%d ", num);
    return 0;
}