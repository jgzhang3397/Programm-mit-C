#include<stdio.h>
#include<stdlib.h>

//=============== #define 宏 vs 函数 ========================
/*
    1.代码长度： 
        宏：每次使用都将宏代码插入程序，造成程序代码加长，除非宏代码很小
        函数： 函数代码只被调用，不被进行复制
    
    2.执行速度
        宏： 更快
        函数 ： 函数需要调用和返回等开销 慢
    
    3.操作符优先级
        宏：不好，多加括号
        函数： 函数参数只在函数调用时求值，结果传递给函数，表达式求值更容易预测
    
    4.带有副作用的参数
        宏：参数可能被替换到宏的多个位置，带副作用的参数求值不可预测
        函数： 函数参数只在传参时求值一次，结果容易控制
    
    5.参数类型
        宏： 宏的参数与类型无关
        函数： 函数的参数与类型有关
    
    6.调试：
        宏： 不方便调试
        函数： 可以逐语句调试
    
    7.递归
        宏：不能递归
        函数： 可以递归
*/


/*
宏的效率比函数高：
    宏在预处理阶段直接值替换
    函数需要调用和返回等开销
*/
//宏
#define MAX(X, Y) ((X)>(Y)?(X):(Y))

//宏可以传类型，函数只能传值/址
#define SIZEOF(type) sizeof(type)
#define MALLOC(num, type) (type*)malloc(num*sizeof(type))

//#undef MAX(X, Y) 代表移除宏定义
//函数
int Max(int a, int b)
{
    return ( a > b ? a : b);
}

void Test01()
{
    int a = 10;
    int b = 11;
    int max = MAX(a++, b++);// ==> ((a++)>(b++)?(a++):(b++));

    printf("%d\n", max);//12
    printf("%d\n", a);//11
    printf("%d\n", b); //13
}

void Test02()
{
    int a = 10;
    int b = 20;
    float c = 3.0f;
    float d = 4.0f;

    //宏无视数据类型 直接调用
    float max = MAX(c, d);
    printf("max = %.2f\n", max);

    // int max = Max(a, b);
    // printf("max = %d\n", max);

    // max = MAX(a, b);
    // printf("max = %d\n", max);
}

void Test03()
{
    //int* p = (int*) malloc(10*sizeof(int));
    int* p = MALLOC(10, int);

    int ret = SIZEOF(int);
    printf("%d\n", ret);//4
}

int main()
{
    Test01();
    //Test02();
    //Test03();
    return 0;
}