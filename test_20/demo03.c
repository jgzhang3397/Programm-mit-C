#include<stdio.h>
/*
=================位段==============
位段的声明和struct是类似的，有两个不同
    1.位段的成员可以是int, unsigned int, signed int
    2.位段的成员后面有一个冒号和数字

    位段 --> 二进制位
    位段的内存分配：
        1.位段的成员可以是int unsigned int signed int 或者是char(属于整型家族)类型
        2.位段的空间上是按照需要以4个字节(int)或者1个字节(char)的方式来开辟的
        3.位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使用位段
    作用：节省空间
    应用：计算机网络 ，信息传输
*/

struct A
{
    int _a:2;//2bit位
    int _b:5;//5bit位
    int _c:10;//10
    int _d:30;//30
    //_a, _b, _c 用第一个4个字节byte（int)
    //_d 用第二个4个字节，
    //注意： 不能大于32

};

struct S
{
    //先开辟一个byte（char）
    char a : 3;
    char b : 4;
    char c : 5;
    char d : 4;
};


int main()
{
    struct A a;
    printf("%d\n", sizeof(a));//8

    struct S s = {0};

    s.a = 10;//1010 大于 3个比特位 --> 只存3个010 == 2
    s.b = 20;//10100 大于 4个比特位 --> 0100 == 4
    s.c = 3;//011 小于 5个比特位 补齐 --> 00011  == 3
    s.d = 4;//100 小于 4个比特位 补齐 --> 0100 == 4
    printf("%d\n", s.a);//2
    printf("%d\n", s.b);//4
    printf("%d\n", s.c);//3
    printf("%d\n", s.d);//4
    return 0;
}
