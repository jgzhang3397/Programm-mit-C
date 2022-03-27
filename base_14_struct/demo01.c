#include<stdio.h>
#include<stddef.h>
//==> p57
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
            5.结构体传参
            6.结构体实现位段（位段的填充&可移植性）
        枚举：
            枚举类型的定义
            枚举的优点
            枚举的使用
        联合体：
            联合类型的定义
            联合的特点
            联合大小的计算
*/

/*
Test01():
    1.=======声明一个结构体类型=========
    声明一个学生类型，想通过学生类型来创建学生变量（对象）
    描述学生：属性-名字+电话+性别+年龄
    2.=============结构体自引用=================

*/
struct Student
{
    char name[20];//名字
    char tele[12];//电话
    char sex[10];//性别
    int age;//年龄
}s4, s5, s6;//全局变量

struct Student s3;//全局变量

//匿名结构体类型创建
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
//typedef关键字
typedef struct Node//节点
{
    int data;
    struct Node* next;//存下一个节点的地址
}node;

void Test01()
{
    //创建的结构体变量,  s1, s2 是局部变量
    struct Student s1;
    struct Student s2;

    //调用匿名结构体
    sa.a = 2;
    //psa = &sa; 编译器会把上面的两个声明当成完全不同的两个类型，所以是非法的
    sa.a = 3;
    printf("%d\n", sa.a);

    //加typedef关键字
    struct Node n1;
    node n2;
}

/*
Test02():
    结构体的初始化

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

void Test02()
{
    struct S s = {'c', {55.6, 30}, 1, 3.14, "hello"};
    printf("%c, %d, %lf, %s\n", s.c, s.a, s.d, s.arr);
    printf("%lf\n", s.st.weight);
}

/*
Test03():
    4.结构体内存对齐
        结构体的对齐规则：
        1.第一个成员在与结构体变量偏移量为0的地址处
        2.其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处
            对齐数：编译器默认的一个对齐数与该成员大小的较小值
            编译器默认的值是8
        3.结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍
        4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数
            （含嵌套结构体的对齐数）的整数倍
    为什么需要内存对齐？
        1.平台原因：某些硬件平台只能在某些地址处取某些特定类型的数据，否则抛出硬件异常
        2.性能原因：数据结构（尤其是栈）应尽可能地在自然边界对齐。原因是：为了访问未对齐的内存，处理器需要做两次
            内存访问，而对齐的内存访问仅需要一次访问
        总的来说：结构体的内存对齐就是拿空间换时间。
    如何设计结构体时，既满足对齐，又要节省空间，如何做到：
        1. 让占用空间小的成员尽量集中在一起
        2. 修改默认对齐数 #pragma pack(8)//设置默认对齐数为8

offsetof

headfile: #include<stddef.h>
size_t offsetof(structName, memberName);//计算结构体成员的偏移量
*/
struct S1
{
    char c1;//1
    //3
    int a;//4
    char c2;//8
    //==12
};

typedef struct S2
{
    char c1;//1
    char c2;//2
    int a;//4
    //==8
}S2;

struct S3
{
    double d;//1
    char c;//8
    int i;//12
    //==16
};

typedef struct S4
{
    char c;//1
    struct S3 s3;//8
    int i;//24
    //==32
}S4;

#pragma pack(4)//设置默认对齐数为4
struct S5
{
    char c;//1
    //3
    double d;//4
    //==12
};
#pragma pack()//取消设置的对齐数

void Test03()
{
    struct S1 s1 = {0};
    printf("s1==%lu\n", sizeof(s1));//12
    printf("s1.a==%lu\n", offsetof(struct S1, a));//4
    printf("s1.c2==%lu\n", offsetof(struct S1, c2));//8

    S2 s2 = {0};
    printf("s2==%lu\n", sizeof(s2));//8
    printf("s2.c2==%lu\n", offsetof(S2, c2));//1
    printf("s2.a==%lu\n", offsetof(S2, a));//4

    struct S3 s3 = {0};
    printf("s3==%lu\n", sizeof(s3));//16

    S4 s4 = {0};
    printf("s4==%lu\n", sizeof(s4));//32
    printf("s4.s3==%lu\n", offsetof(S4, s3));
    printf("s4.i==%lu\n", offsetof(S4, i));


    struct S5 s = {0};
    printf("%lu\n", sizeof(s));//12

    printf("==============\n");

    printf("%lu\n", offsetof(struct S5, c));//0
    printf("%lu\n", offsetof(struct S5, d));//4
}

int main()
{
    //Test01();
    //Test02();
    Test03();
    return 0;
}

