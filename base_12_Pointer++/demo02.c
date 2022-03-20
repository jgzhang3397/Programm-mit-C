//====数组参数，指针参数=======

#include<stdio.h>
//=============复习==========
void Test01()
{
    // 字符指针
    char ch = 'w';
    char* p = &ch;
    const char *p2 = "abcdef";//把首字符a的地址交给p2
    //指针数组 - 数组 - 存放指针的数组
    int* arr[10];
    char* chc[5];
    //数组指针 - 指向数组的指针
    int* p3; //整型指针 - 指向整型的指针，类型int*
    char* p4; //字符指针 - 指向字符的指针，类型char*

    int arr2[5]; //数组
    int (*pa)[5] = &arr2;//取出数组的地址, pa就是一个数组指针， 类型 int(*)[]
}

void demo01_T2(int arr[], int sz)//ok? --> ja
{
    printf("===> int arr[]\n");
    int i;
    for(i=0; i<sz; i++)
    {
        printf("arr1[%d] = %d\n", i, arr[i]);
    }

}
void demo02_T2(int arr[10], int sz)//geht es --> 100% ja
{
    printf("===> int arr[10]\n");
    int i;
    for(i=0; i<sz; i++)
    {
        printf("arr1[%d] = %d\n", i, arr[i]);
    }
}

void demo03_T2(int *arr, int sz)//ok? --> emmm...natuerlich
{
    printf("===> int *arr\n");
    int i;
    for(i=0; i<sz; i++)
    {
        printf("arr1[%d] = %d\n", i, *(arr+i));
    }
}

void demo04_T2(int *arr[10], int sz)//ok? --> auf jeden fall
{
    printf("===> int *arr[10]\n");
    int i;
    for(i=0; i<sz; i++)
    {
        printf("*arr2[%d] = %p\n", i, arr[i]);
    }
}
void demo05_T2(int **arr, int sz)//ok? --> bestimmt
{
    printf("===> int **arr\n");
    int i;
    for(i=0; i<sz; i++)
    {
        printf("*arr2[%d] = %p\n", i, *(arr+i));
    }
}

void Test02()
{
    int arr1[10] = {0,1,2,3,4,5,6,7,8,9};
    int sz1 = sizeof(arr1)/sizeof(arr1[0]);

    int *arr2[10] = {0,1,2,3,4,5,6,7,8,9};
    int sz2 = sizeof(arr2)/sizeof(arr2[0]);

    // demo01_T2(arr1, sz1);
    // demo02_T2(arr1, sz1);
    // demo03_T2(arr1, sz1);

    demo04_T2(arr2, sz2);
    demo05_T2(arr2, sz2);

}

void demo01_T3(int arr[3][5])
{
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<5; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void demo02_T3(int arr[][5])
{
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<5; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
// void demo03_T3(int arr[3][])//error 可以省略行，不可省略列
// {
// }
// void demo04_T3(int *arr)//error
// {
// }

// void demo05_T3(int ** arr, int n, int m)//error
// {
// }

void demo06_T3(int (*arr)[5], int n, int m)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%d ", (*arr+i)[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Test03()
{
    int arr[3][5] = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
    int sz = sizeof(arr)/sizeof(arr[0][0]);//总长
    int n = sizeof(arr)/sizeof(arr[0]);//列长
    int m = sz/n;//行长

    demo01_T3(arr);//二维数组传参
    demo02_T3(arr);

    //demo03_T3(arr);
    //demo04_T3(arr);
    //demo05_T3(arr, n, m);

    demo06_T3(arr, n, m);
}

//一级指针p，传给函数
void print(int *p, int sz)
{
    int i = 0;
    for ( i = 0; i < sz; i++)
    {
        printf("%d ", *p + i);
    }  
    printf("\n");
}

void demo01_T4(int *p)
{
    printf("%d\n", *p);
}

void Test04()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = arr;
    int sz = sizeof(arr)/sizeof(arr[0]);
    print(p, sz);
    print(arr, sz);

    int n = 10;
    int *pi = &n;
    demo01_T4(pi);
    demo01_T4(&n);
}

//=============二级指针传参=======
void demo01_T5(int** ptr)
{
    printf("num = %d\n", **ptr);
}

void Test05()
{
    int n = 10;
    int *p = &n;
    int **pp = &p;
    demo01_T5(pp);//ok
    demo01_T5(&p);//ok
}

/*
=======函数指针=========
数组指针 --> 指向数组的指针
函数指针 --> 指向函数的指针 --> 存放函数地址的指针
*/
int add(int x, int y)
{
    return x + y;
}

void Test06()
{
    int a = 10;
    int b = 20;
    int arr[10] = {0};
    int (*p)[10] = &arr;//数组指针，指向数组

    printf("num == %d\n", add(a, b));//num == 30

    //&函数名 和 函数名 都是函数的地址
    //函数也有地址
    printf("%p\n", &add);//0x100003c60
    printf("%p\n", add);//0x100003c60

    //可以不取地址
    int (*pa)(int, int) = &add;
    int (*pb)(int, int) = add;

    //可以不解引用
    printf("num = %d\n", (pa)(a, b));
    printf("num = %d\n", (*pa)(a, b));
    printf("num = %d\n", (pb)(a, b));
    printf("num = %d\n", (*pb)(a, b));
}

void Print(char* str)
{
    printf("%s\n", str);
}

void Test07()
{
    void (*p)(char*) = Print;
    (*p)("Hello world\n");
}

void Test08()
{
    //代码1
    ( * (void(*)()) 0)();
    //把0强制转换成：void(*)() 函数指针类型 -0就是一个函数的地址 // ahnlich  wie (int*) arr;
    //调用0地址处的该函数

    //代码2
    //void(*)(int) --> 函数指针
    void(*    signal(  int, void(*)(int)  )     )(int);
    //signal 函数 的两个参数，一个int 另一个函数指针，其返回类型也是函数指针
    //便于理解
    typedef void(* pfun_t)(int);
    pfun_t signal(int, pfun_t);
}

/*
Test09():
    ===========函数指针数组==============
*/
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

void Test09()
{
    //指针数组
    int* arr[5];
    //需要一个数组，可以存放四个函数的地址 -函数指针的数组
    //int (*pa)(int, int) = Add;//Sub, Mul, Div
    int (*pa[4])(int, int) = {Add,Sub,Mul,Div};//函数指针的数组
    int i = 0;
    for ( i = 0; i < 4; i++)
    {
        printf (" Result : %d\n", pa[i](2, 3));
    }
}

int main()
{
    //Test01();
    //Test02();
    //Test03();
    //Test04();
    //Test05();
    //Test06();
    //Test07();
    //Test08();
    Test09();
    return 0;
}
