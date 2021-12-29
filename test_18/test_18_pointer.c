/*
1.字符指针
2.数组指针
3.指针数组
4.数组传参和指针传参
5.函数指针
6.函数指针数组
7.指向函数指针数组的指针
8.回调函数
9.指针和数组面试题的解析

指针：
    定义：
    1.指针就是变量，用来存放地址
    2.指针的大小4/8个字节（32位）/（64位）
    3.指针有类型，类型决定指针的步长，指针解引用的权限
    4.指针的运算
*/
#include<stdio.h>
// void test(int arr[])
// {
//     int sz = sizeof(arr)/sizeof(arr[0]);//x64 --> 8/4
//     printf("%d\n", sz);//2
// }
// int main()
// {
//     int arr[10] ={0};
//     test(arr);
//     return 0;
// }

// int main()
// {
//     char ch = 'w';
//     char* pc = &pc;
//     char arr[] = "abcdef";
//     char* pa = arr;
//     printf("%s\n", arr);
//     printf("%s\n", pa);
//     return 0;
// }

// int main()
// {
//     const char* pc = "abcdef";//"abcdef" 是常量字符串 *pc里存放的是字符串首字符a的地址
//     // *pc = 'w'; //segment fault
//     printf("%c\n", *pc);//a
//     printf("%s\n", pc);//abcdef
//     return 0;
// }

// int main()
// {
//     char arr1[] = "abcdef";
//     char arr2[] = "abcdef";
//     const char *p1 = "abcdef";
//     const char *p2 = "abcdef";

//     if(arr1 == arr2)
//     {
//         printf("gleich\n");
//     }
//     else
//     {
//         printf("nicht gleich\n");//两个数组，两个空间，两个地址
//     }
//     if(p1 == p2)
//     {
//         printf("gleich\n");//常量字符串 不能修改， 
//     }
//     else
//     {
//         printf("nicht gleich\n");
//     }
//     return 0;
// }

// //指针数组 是数组
// int main()
// {
//     int arr[10] = {0}; //整型数组
//     char ch[5] = {0}; //字符数组

//     int* parr[4];//存放整型指针的数组
//     char* pch[5];//存放字符指针的数组

//     return 0;
// }

// int main()
// {
//     int a = 10;
//     int b = 20;
//     int c = 30;
//     int d = 40;
//     int* arr[4] = {&a, &b, &c, &d};

//     int i = 0;
//     for ( i = 0; i < 4; i++)
//     {
//         printf("%d ", *arr[i]);
//     }
    
//     return 0;
// }

// int main()
// {
//     int arr1[] = {1,2,3,4,5};
//     int arr2[] = {2,3,4,5,6};
//     int arr3[] = {3,4,5,6,7};

//     int* parr[] = {arr1, arr2, arr3};

//     int i = 0;
//     for ( i = 0; i < 3; i++)
//     {
//         int j = 0;
//         for ( j = 0; j < 5; j++)
//         {
//             printf("%d ", *(parr[i] + j));
//         }
//         printf("\n");
//     }
    
//     return 0;
// }

// //数组指针 是 指针
// int main()
// {
//     // int *p = NULL; //p 是整型指针，指向整型，存放整型的地址
//     // char *pc = NULL; //pc 是字符指针，指向字符，存放字符的地址

//     // //数组指针，指向数组，存放数组的地址
//     // int arr[10] = {0};
//     // //arr -- 首元素地址
//     // //&arr[0] --首元素地址
//     // //&arr --数组的地址

//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//     int (*p)[10] = &arr;//数组的地址-->存储
// }

// int main()
// {
//     char* arr[5];//指针数组
//     char* (*pa)[5] = &arr;//数组指针 指向数组
//     //pa --> 指针变量的名字
//     //* --> pa 是指针
//     //[5] --> pa 指向的数组是五个元素
//     //char* --> pa 指向的数组的数据类型是char*

//     int arr2[10] = {0};
//     int (*pa2)[10] = &arr2;
//     return 0;
// }

// int main()
// {
//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//     // int (*pa)[10] = &arr;//pa --> 数组的地址
//     // int i = 0;
//     // // for ( i = 0; i < 10; i++)
//     // // {
//     // //     printf("%d ", (*pa)[i]);
//     // // }

//     // for ( i = 0; i < 10; i++)
//     // {
//     //     printf("%d ", *(*pa + i));//*pa == arr
//     // }

//     int *pa = arr;
//     int i = 0;
//     for ( i = 0; i < 10; i++)
//     {
//         printf("%d ", *(pa+i));
//     }
//     return 0;
// }

// //参数是数组
// void print1(int arr[3][5], int x, int y)//数组传参-->数组形式
// {
//     int i = 0;
//     int j = 0;
//     for ( i = 0; i < x; i++)
//     {
//         for(j = 0; j < y; j++)
//         {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }  
// }

// //参数是指针
// void print2(int (*pa)[5], int x, int y)
// {
//     int i = 0;
//     for ( i = 0; i < x; i++)
//     {
//         int j = 0;
//         for(j = 0; j < y; j++)
//         {
//             //pa首行地址
//             //pa + i --> 第i行地址
//             //*(pa + i) --> 第i行地址的首个元素地址,也就是找到了第i行的内容
//             //(*(pa + i))[j] --> 第i行数组的下标
//             //*(pa + i) + j --> 第i行第j个地址的地址
//             //*(*(pa + i) + j) --> 对第i行第j个地址的地址解应用，得到元素内容

//             //printf("%d ", *(*(pa + i) + j));
//             //printf("%d ", (*(pa + i))[j]);//*(pa + i) == pa[i]
//             printf("%d ", pa[i][j]);//--> * (pa[i] + j), 把pa[i]看成一个整体
//         }
//         printf("\n");
//     }
    
// }
// int main()
// {
//     int arr[3][5] = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
//     print1(arr, 3, 5);//数组名arr --> 首元素地址 -->第一行
//     //把arr理解成1维数组，总共三个元素，三行-->五个整型
//     print2(arr, 3, 5);//arr表示首元素地址 第一行

//     // int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//     // int* pa = arr;
//     // int i = 0;
//     // for ( i = 0; i < 10; i++)
//     // {
//     //     printf("%d ", pa[i]);
//     //     printf("%d ", *(pa + i));
//     //     printf("%d ", *(arr + i));
//     //     printf("%d ", arr[i]);//arr[i] = *(arr + i) = *(pa + i)
//     // }
    
//     return 0;
// }

int main()
{
    int arr[5];//arr 是 一个五个元素的整型数组
    int* parr1[10];//是 一个数组，10个元素，每个元素类型是int*，是一个指针数组
    int (*parr2)[10];//是 一个指针，指向一个数组，数组有十个元素，每个元素类型是int, 数组指针
    int (*parr3[10])[5];//是 一个数组，数组名parr3[10],([]的优先级高)，元素类型：int (*+数组名）[5] 
    // 数组10个元素，每个元素是一个数组指针，该数组指针指向的数组有5个元素，每个元素是int
    //是 数组指针 数组
    return 0;
}