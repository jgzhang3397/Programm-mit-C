#include<stdio.h>
/*
内置类型：char, short, int, long, float, double
复杂类型：
    自定义类型：
        结构体：
            1.结构体类型的声明
                struct tag
                {
                    member-list;
                }variable-list;
            2.结构的自引用
            3.结构体变量的定义和初始化
            4.结构体内存对齐
            结构体传参
            结构体实现位段（位段的填充&可移植性）
        枚举：
            枚举类型的定义
            枚举的优点
            枚举的使用
        联合体：
            联合类型的定义
            联合的特点
            联合大小的计算
*/

//1.=======声明一个结构体类型=========
//声明一个学生类型，想通过学生类型来创建学生变量（对象）
//描述学生：属性-名字+电话+性别+年龄
struct Student
{
    char name[20];//名字
    char tele[12];//电话
    char sex[10];//性别
    int age;//年龄
}s4, s5, s6;//全局变量

struct Student s3;//全局变量

/*
匿名结构体类型创建
*/
struct 
{
    int a;
    char b;
    float c;
}sa;

struct
{
   int a;
   char b;
   float c;
}* psa;//结构体指针

//2.=============结构体自引用=================
/*
    数据结构
    数据在内存中存储的结构

    链表
    1，2，3，4，5
*/
// struct Node//节点
// {
//     int data;
//     struct Node* next;//存下一个节点的地址
// };


/*
typedef关键字
*/
typedef struct Node//节点
{
    int data;
    struct Node* next;//存下一个节点的地址
}node;

// int main()
// {
//     //创建的结构体变量,  s1, s2 是局部变量
//     struct Student s1;
//     struct Student s2;

//     //调用匿名结构体
//     sa.a = 2;
//     //psa = &sa; 编译器会把上面的两个声明当成完全不同的两个类型，所以是非法的
//     sa.a = 3;
//     printf("%d\n", sa.a);

//     //加typedef关键字
//     struct Node n1;
//     node n2;
//     return 0;
// }

/*
=================3.结构体的初始化===================
*/
struct T
{
    double weight;
    short age;
};

struct S
{
    char c;
    struct T st;
    int a;
    double d;
    char arr[20];
};

// int main()
// {
//     struct S s = {'c', {55.6, 30}, 1, 3.14, "hello"};
//     printf("%c, %d, %lf, %s\n", s.c, s.a, s.d, s.arr);
//     printf("%lf\n", s.st.weight);
//     return 0;
// }

//====================4.结构体内存对齐==========================

struct S1
{
    char c1;
    int a;
    char c2;
};

struct S2
{
    char c1;
    char c2;
    int a;
};

int main()
{
    struct S1 s1 = {0};
    printf("%d\n", sizeof(s1));//12

    struct S2 s2 = { 0 };
    printf("%d\n", sizeof(s2));//8
    return 0;
}