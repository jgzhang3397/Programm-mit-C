#include<stdio.h>
/*
Test01():
    sizeof()里的表达式不参与运算
*/
void Test01()
{
    short s = 0;
    int a = 10;
    printf("%lu\n", sizeof(s=a+5));//2 
    printf("%d\n", s);//0
}

/*
Test02():
    ~ 按2进制位取反
    0000 0000 0000 0000 0000 0000 0000 0000 == a 原反补码相同

    1111 1111 1111 1111 1111 1111 1111 1111 -> ~a 的补码
    1111 1111 1111 1111 1111 1111 1111 1110 -> 反码 
    1000 0000 0000 0000 0000 0000 0000 0001 -> 原码==-1
*/
void Test02()
{
    int a = 0;
    printf("%d\n", ~a);//-1
}

/*
Test03():
    a == 11
    0000 1011

    1
    0000 0001
    1<<2: 将1bit向左移动两位
    0000 0100

    a|(1<<2)
    0000 1011
    0000 0100
    0000 1111 == result= a = 15

    ~(1<<2)
    1111 1011

    a & (~(1<<2))
    0000 1111
    1111 1011
    0000 1011 == result2 = 11

*/
void Test03()
{
    int a = 11;
    a = a|(1<<2);
    printf("%d\n", a);//15

    int result2 = a &(~(1<<2));
    printf("%d\n", result2);//11
}

/*
Test04():
  i++ and ++i ?

  int a = (int)3.14;//强制转换
*/
void Test04()
{
    int a = 10;
    int b = 10;
    printf("%d\n", ++a);//前置++， 先++，后使用  11
    printf("%d\n", b++);//后置++， 先使用，后++，10
}

/*
Test05():
    pointer and arrays
*/
void demo01(int arr[])
{
    printf("%lu\n", sizeof(arr));//arr 是指针变量 8
}
void demo02(char ch[])
{
    printf("%lu\n", sizeof(ch));//ch 是指针变量 8 
}
void demo03(int* arr)
{
    printf("%lu\n", sizeof(arr));//arr 是指针变量 8
}
void demo04(char* ch)
{
    printf("%lu\n", sizeof(ch));//ch 是指针变量 8 
}
void Test05()
{
    int arr[10]={0};
    char ch[10]={0};
    printf("%lu\n", sizeof(arr));//4*10
    printf("%lu\n", sizeof(ch));//1*10 
    demo01(arr);//数组传参传的是首元素地址，需要指针接收
    demo02(ch);
    demo03(arr);
    demo04(ch);
}

/*
Test06():
    0&&NaN = 0, 右边不再算了
    1||NaN = 1, 右边不算
*/
void Test06()
{
    int i = 0, a = 1, b = 2, c = 3, d = 4;
    // i = a++ && ++b && d++; 
    i = a++||++b||d++; 
    printf("i = %d\n", i);
    printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
}

/*
Test07():
    三目操作符
    a>b?a:b 
    ==
    if(a>b)
        max = a;
    else
        max = b;
*/
void Test07()
{
    int a = 10, b = 20;
    int max = (a>b?a:b);
    printf("Max = %d\n", max);
}

/*
Test08():
    (Condition1, C2, C3,...,CN)从左到右去算，结果取最后一个 result = CN;
*/
void Test08()
{
    int a = 1;
    int b = 2;
    int c = (a>b, a=b+10, a, b= a+1); // b = 13， 从左到右去算，结果取最后一个
    printf("%d\n", c);
}

/*
Test09():
    struct
*/
struct stu
{
    char name[20];
    int age;
    int id[20];
};
void Test09()
{
    int a = 10;
    //use a struct to create and initialize a s1
    struct stu s1 = {"Mike", 20, 979877};
    struct stu* ps = &s1;
    printf("%s\n", ps->name);
    printf("%s\n", (*ps).name);
    printf("%s\n", s1.name);
    printf("%d\n", s1.age);
    printf("%d\n", s1.id);
}

/*
Test10()|Test11()|Test12():
    整型提升
*/
void Test10()
{
    char a = 3;
    //00000000000000000000000000000011
    //00000011 -a
    char b = 127;
    //00000000000000000000000001111111
    //01111111 -b
    char c = a+b;
    //00000000000000000000000000000011 -a 整型提升
    //00000000000000000000000001111111 -b
    //00000000000000000000000010000010 -c
    //10000010 -c
    //11111111111111111111111110000010 -补码 = 反码+1
    //11111111111111111111111110000001 -反码
    //10000000000000000000000001111110 -原码 - -126
    printf("%d\n", c);//-126
}

void Test11()
{
    char a = 0xb6; //11010110
    short b = 0xb600;
    int c = 0xb6000000;

    //result of comparison of constant 182 with expression of type 'char' is always false 
    if (a == 0xb6)
        printf("a");
    if (b == 0xb600)
        printf("b");
    if (c == 0xb6000000)
        printf("c");
}

void Test12()
{
    char c = 1;
    printf("%lu\n", sizeof(c));//1

    printf("%lu\n", sizeof(+c));//4
    printf("%d\n", +c);//1

    printf("%lu\n", sizeof(!c));//4
    printf("%d\n", !c);//0
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
    //Test09();
    //Test10();
    //Test11();
    Test12();
    return 0;
}
