//====数组参数，指针参数=======

//#include<stdio.h>
//=============复习==========
// int main()
// {
//     // 字符指针
//     char ch = 'w';
//     char* p = &ch;
//     const char *p2 = "abcdef";//把首字符a的地址交给p2
//     //指针数组 - 数组 - 存放指针的数组
//     int* arr[10];
//     char* ch[5];
//     //数组指针 - 指向数组的指针
//     int* p3; //整型指针 - 指向整型的指针，类型int*
//     char* p4; //字符指针 - 指向字符的指针，类型char*

//     int arr2[5]; //数组
//     int (*pa)[5] = &arr2;//取出数组的地址, pa就是一个数组指针， 类型 int(*)[]

//     return 0;
// }

#include<stdio.h>
// void test(int arr[])//ok? --> ja
// {

// }
// void test(int arr[10])//geht es --> 100% ja
// {

// }
// void test(int *arr)//ok? --> emmm...natuerlich
// {

// }
// void test2(int *arr[20])//ok? --> auf jeden fall
// {

// }
// void test2(int **arr)//ok? --> bestimmt
// {

// }
// int main()
// {
//     int arr[10] = {0};
//     int *arr2[20] = {0};
//     test(arr);
//     test2(arr);
// }

// // void test1(int arr[3][5])
// // {

// // }
// // void test2(int arr[][5])
// // {

// // }
// // void test3(int arr[3][])//error 可以省略行，不可省略列
// // {

// // }
// // void  test4(int *arr)//error
// // {

// // }
// // void test5(int **arr)//error
// // {

// // }
// void test6(int (*arr)[5])
// {

// }
// int main()
// {
//     int arr[3][5] = {0};

//     // test1(arr);//二维数组传参
//     // test2(arr);
//     // test3(arr);
//     // test4(arr);
//     // test5(arr);
//     test6(arr);
//     return 0;
// }

// void print(int *p, int sz)
// {
//     int i = 0;
//     for ( i = 0; i < sz; i++)
//     {
//         printf("%d ", *p + i);
//     }
    
// }
// int main()
// {
//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//     int *p = arr;
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     //一级指针p，传给函数
//     print(p, sz);
//     return 0;
// }

// void test1(int* p)
// {

// }
// int main()
// {
//     int a = 10;
//     int* p1 = &a;
//     //beide geht es
//     test1(&a);
//     test1(p1);
//     return 0;
// }

//=============二级指针传参=======
#include<stdio.h>
// void test(int** ptr)
// {
//     printf("num = %d\n", **ptr);
// }
// int main()
// {
//     int n = 10;
//     int *p = &n;
//     int **pp = &p;
//     test(pp);//ok
//     test(&p);//ok
//     return 0;
// }

// void test(int **p)
// {

// }
// int main()
// {
//     int *ptr;
//     int **pptr = &ptr;
//     test(&ptr);
//     test(pptr);

//     int* arr[10];
//     test(arr);
//     return 0;
// }

//=======函数指针=========
//数组指针 --> 指向数组的指针
//函数指针 --> 指向函数的指针 --> 存放函数地址的指针
// int add(int x, int y)
// {
//     return x + y;
// }
// int main()
// {
//     int a = 10;
//     int b = 20;
//     int arr[10] = {0};
//     int (*p)[10] = &arr;//数组指针，指向数组
//     //printf("num == %d\n", add(a, b));

//     // //&函数名 和 函数名 都是函数的地址
//     // printf("%p\n", &add);//函数也有地址
//     // printf("%p\n", add);

//     //可以不取地址
//     int (*pa)(int, int) = &add;
//     int (*pb)(int, int) = add;
//     //可以不解引用
//     printf("num = %d\n", (pa)(a, b));
//     printf("num = %d\n", (*pa)(a, b));
//     printf("num = %d\n", (pb)(a, b));
//     printf("num = %d\n", (*pb)(a, b));
//     return 0;
// }

// void Print(char* str)
// {
//     printf("%s\n", str);
// }
// int main()
// {
//     void (*p)(char*) = Print;
//     (*p)("Hello world\n");
//     return 0;
// }

// //代码1
// （*（void(*)())0)();
// //把0强制转换成：void(*)() 函数指针类型 -0就是一个函数的地址 // ahnlich  wie (int*) arr;
// //调用0地址处的该函数

// //代码2
// //void(*)(int) --> 函数指针
// void(*    signal(  int, void(*)(int)  )     )(int);
// //signal 函数 的两个参数，一个int 另一个函数指针，其返回类型也是函数指针
// //便于理解
// typedef void(* pfun_t)(int);
// pfun_t signal(int, pfun_t);

//===========函数指针数组==============
// int Add(int x, int y)
// {
//     return x + y;
// }
// int Sub(int x, int y)
// {
//     return x - y;
// }
// int Mul(int x, int y)
// {
//     return x * y;
// }
// int Div(int x, int y)
// {
//     return x / y;
// }
// int main()
// {
//     //指针数组
//     int* arr[5];
//     //需要一个数组，可以存放四个函数的地址 -函数指针的数组
//     //int (*pa)(int, int) = Add;//Sub, Mul, Div
//     int (*pa[4])(int, int) = {Add,Sub,Mul,Div};//函数指针的数组
//     int i = 0;
//     for ( i = 0; i < 4; i++)
//     {
//         printf (" Result : %d\n", pa[i](2, 3));
//     }
    
// }

// //小练习
// char* my_strcpy(char* dest, const char* src);
// //写一个函数指针pf，能够指向my_strcpy
// char*（*pf)(char*, const char*) = my_strcpy;
// //写一个函数指针数组pfArr，能够存放4个my_strcpy函数的地址
// char* (*pfArr[4])(char*, const char*) = {0};

//==============计算器============
int Add(int x, int y)
{
    return x + y;
}
int Sub(int x, int y)
{
    return x - y;
}
int Mul(int x, int y)
{
    return x * y;
}
int Div(int x, int y)
{
    return x / y;
}
int Xor(int x, int y)
{
    if(x == y)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void menu()
{
    printf("***************************\n");
    printf("****1. add     2. sub******\n");
    printf("****3. mul     4. div******\n");
    printf("****5. xor     0. exit*****\n");
    printf("***************************\n");
}
// int main()
// {
//     int input = 0;
//     int x, y;
//     int (*pfArr[])(int, int)= {0, Add, Sub, Mul, Div, Xor};
//     int sz = sizeof(pfArr)/sizeof(pfArr[0]);
//     do
//     {
//         menu();
//         printf("Bitte waehlen Sie : ->");
//         scanf("%d", &input);
//         if(input>=1 && input < sz)
//         {
//             printf("请输入两个操作数x 和 y:>");
//             scanf("%d%d", &x, &y);
//             // int result = (*pfArr[input])(x, y);
//             int result = pfArr[input](x, y);
//             printf("%d\n", result);
//         }
//         else if(input == 0)
//         {
//             printf("Exit\n");
//             break;
//         }
//         else
//         {
//             printf("Error\n");
//         }
//     } while (input); 
// }

//回调函数
void Calc(int (*pf)(int, int))
{
    int x, y;
    printf("请输入两个操作数x 和 y:>");
    scanf("%d%d", &x, &y);
    //printf("%d\n", pf(x, y));
    printf("%d\n", (*pf)(x, y));
}
int main()
{
    int input = 0;
    int x, y;
    do
    {
        menu();
        printf("Bitte waehlen Sie : ->");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            Calc(Add);//函数名就是函数的地址
            break;
        case 2:
            Calc(Sub);
            break;
        case 3:
            Calc(Mul);
            break;
        case 4:
            Calc(Div);
            break;
        case 5:
            Calc(Xor);
            break;
        case 0:
            printf("Exit!\n");
            break;
        default:
            break;
        }
    } while (input); 
    return 0;
}