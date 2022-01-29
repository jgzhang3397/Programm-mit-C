#include<stdio.h>
/*
结构体传参，传地址形参，用指针调用
原因：
    函数传参时，参数需要压栈，会有时间和空间上的系统开销
    如果传递一个结构体对象的时候，结构体过大，参数压栈的系统开销比较大，所以会导致性能的下降
*/
struct S
{
    char c;
    int a;
    double d;
};

void Test01(struct S* ps)
{
    ps->a = 100;
    ps->c = 'w';
    ps->d = 3.14;
}

//传值
void Print1(struct S tmp)
{
    printf("%d, %c, %lf\n", tmp.a, tmp.c, tmp.d);
}

//传地址
void Print2(struct S* ps)
{
    printf("%d, %c, %lf\n", ps->a, ps->c, ps->d);
}

int main()
{
    struct S s = {0};
    Test01(&s);
    Print1(s);
    Print2(&s);//功能更加强大，权限更多
    return 0;
}