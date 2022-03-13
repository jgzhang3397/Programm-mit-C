//Pointer umbrechnen
#include<stdio.h>
// int main()
// {
//     int arr[10]={1,2,3,4,5,6,7,8,9,10};
//     int i = 0;
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     // int* p = arr;
//     // for ( i = 0; i < sz; i++)
//     // {
//     //     printf("%d\n", *p);
//     //     p++;
//     // }
//     int* p =&arr[9];
//     for ( i = 0; i < sz; i++)
//     {
//         printf("%d\n", *p);
//         p--;
//     }
//     return 0;
// }

// int main()
// {
//     int arr[10]={1,2,3,4,5,6,7,8,9,10};
//     printf("%lu\n", &arr[9]-&arr[0]);//9
//     printf("%d\n", &arr[0]-&arr[9]);//-9
//     return 0;
// }
// int my_strlen(char* str)
// {
//     char* start = str;
//     char* end = str;
//     while (*end != '\0')
//     {
//         end++;
//     }
//     return end - start;  
// }
// int main()
// {
//     char arr[]="Hello";
//     int len = my_strlen(arr);
//     printf("%d\n", len);
//     return 0;
// }
// int main()
// {
//     int arr[10] = {0};
//     printf("%p\n", arr);//地址，首元素地址
//     printf("%p\n", arr+1);
//     printf("%p\n", &arr[0]);
//     printf("%p\n", &arr[0]+1);
//     printf("%p\n", &arr);//整个数组的地址
//     printf("%p\n", &arr+1);
//     //1. &arr- &数组名 -数组名不是首元素的地址-数组名表示整个数组 -&数组名 取得是整个数组的地址
//     //2. sizeof(arr) - sizeof(数组名)- 数组名表示整个数组 -sizeof(数组名)计算的是整个数组的大小
//     return 0;
// }
// int main()
// {
//     int arr[10]={0};
//     int* p = arr;
//     int i = 0;
//     for ( i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
//     {
//         *(p+i) = i;
//         printf("%d\n", *(p+i));
//     }
    
//     // for ( i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
//     // {
//     //     printf("%p <=============>  %p\n", p+i, &arr[i]);
//     // }
//     return 0;
// }

// //=======二级指针===========
// int main()
// {
//     int a = 10;
//     int* pa = &a;
//     int** ppa = &pa;//二级指针
//     //int*** pppa = &ppa;//三级指针。。
//     **ppa = 20;
//     printf("%d\n", **ppa);//20
//     printf("%d\n", *pa);//20
//     printf("%d\n", a);//20
// }

//指针数组
//数组指针
int main()
{
    int a = 10, b = 20, c = 30;
    int* pa = &a;
    int* pb = &b;
    int* pc = &c;
    int* arr[]={&a, &b, &c};//指针数组
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d\n", *(arr[i]));
    }
    
    return 0;
}