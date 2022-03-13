#include<stdio.h>
/*
Schwerpunkt
    1.  Was ist Pointer?
    2.  Pointer und die Sort des Pointers
    3.  Pointer, die nicht begrenzt nicht initialisiert etw.. sollen vermeiden
    4.  Pointer umberechnen
        Pointer und Arrays
        2 stufe Pointer
        Pointer-Arrays
        
*/

/*
Test01():
    p = Pointer-Variante, also die Addresse 
*/
void Test01()
{
    int a = 10;
    int* p = &a;
}

/*
Test02():
    size of pointer variable
*/
void Test02()
{
    printf("%lu\n", sizeof(char*));//8
    printf("%lu\n", sizeof(short*));//8
    printf("%lu\n", sizeof(int*));//8
    printf("%lu\n", sizeof(double*));//8
}   

/*
Test03():
    指针类型决定了指针进行解引用操作时，能够访问的空间的大小
    int* p; *p能访问4个字节
    char* p; *p能访问1个字节
    double* p; *p能访问8个字节

    指针类型决定了：指针走一步走多远
    int* p; p+1 --> 4
    char* p; p+1 --> 1
    double* p; p+1 --> 8
*/
void Test03()
{
    int a = 0x11223344;
    int* pa = &a;
    char* pc = &a;
    
    printf("%p\n", pa);   //0x7ffeefbff2fc
    printf("%p\n", pa+1); //0x7ffeefbff300
    printf("%p\n", pc);   //0x7ffeefbff2fc
    printf("%p\n", pc+1); //0x7ffeefbff2fd
    
}

/*
Test04():
    arr 数组名--首元素地址
*/
void Test04()
{
    int arr[10]={0};
    int* p = arr;
    //char* p = arr;
    for ( int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        *(p+i) = i;
        printf("%d ", *(p+i));
    }
}

/*
Test05():
    局部变量不初始化，默认是随机值
    局部指针变量被初始化成随机值，应避免成野指针！！
*/
void Test05()
{
    int a = 0; 
    int* p; 
    *p = 20;
}

/*
Test06():

*/
int* demo()
{
    int a = 10;//局部变量，demo()完结束，地址释放
    return &a;
}
void Test06()
{
    int* p = demo();
    printf("%d\n", *p);
}

/*
Test07():
    Wie kann man es vermeiden?
    1. Pointer initialisieren

    2. Pass auf die Pointer auf den Begrenzung
*/
void Test07()
{
    int a = 10;
    int* pa = &a;//init
    int* pb = NULL;//init

    int a = 10;
    int* pa = &a;
    *pa = 20;
    pa = NULL;
}
int main()
{
    //Test01();
    //Test02();
    //Test03();
    //Test04();
    //Test05();
    //Test06();
    Test07();
    return 0;
}
