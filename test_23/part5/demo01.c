#include<stdio.h>
#include<stddef.h>

/*
offsetof: 计算偏移量
*/
struct S
{
    char c1;
    int a;
    char c2;
};

void Test01()
{
    printf("%lu\n", offsetof(struct S, c1));
    printf("%lu\n", offsetof(struct S, a));
    printf("%lu\n", offsetof(struct S, c2));
}

/*
struct_name* ==> struct S* : 结构体指针
((struct_name*)0) ==> : 结构体指针类型的值是0 类比arr[0],是结构体的地址
((struct_name*)0)->member_name ==> : ((struct S*)0)->c1

*/
#define OFFSETOF(struct_name, member_name) (unsigned long)&(((struct_name*)0)->member_name)
void Test02()
{
    printf("%lu\n", OFFSETOF(struct S, c1));
    printf("%lu\n", OFFSETOF(struct S, a));
    printf("%lu\n", OFFSETOF(struct S, c2));
}

int main()
{
    //Test01();
    Test02();
    return 0;
}