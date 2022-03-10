#include<stdio.h>
/*
Test01():
    what's "/" & "%" meaning?
*/
void Test01()
{
    int a = 5/2;//2
    int b = 5%2;//1
    printf("%d\n", a);
    printf("%d\n", b);
}

/*
Test02():
    what's ">>" meaning?
    将一个运算对象的各二进制位全部右移若干位，正数左补0，负数左补1.
    : >>  means moving to the right

    binary bit 1 move to the right
    a = 0000 0000 0000 0000 0000 0000 0001 0000 == 16
    右移操作符
    1.算术右移
     右边丢弃，左边补原符号位。
    2.逻辑右移
     右边丢弃，左边补零
    b = 0000 0000 0000 0000 0000 0000 0000 1000 == 8
*/
void Test02()
{
    int a = 16;
    int b = a >> 1;
    printf("%d\n", b);//8
}

/*
Test03():
    整数的binar表示有，原码， 反码， 补码
    正整数的原反补码相同
    储存到内存的是补码
 a= 1000 0000 0000 0000 0000 0001 - 原码 = -1
    1111 1111 1111 1111 1111 1110 - 反码，符号位不变，其他取反
    1111 1111 1111 1111 1111 1111 - 补码 = 反码+1

 b= 1111 1111 1111 1111 1111 1111 - 补码
    1111 1111 1111 1111 1111 1110 - 反码 = 补码-1
    1000 0000 0000 0000 0000 0001 - 原码 = -1

    正整数的原反补是相同的，所以Test02的a=16可以直接移动
*/
void Test03()
{
    int a = -1;
    int b = a >> 1;
    printf("%d\n", b);//-1
}

/*
Test04():
    左移操作符
    将一个运算对象的各二进制位全部左移若干位（左边的二进制丢弃，右边补0）
    a = 0000...0101
    左边丢弃，右边补0
    b = 0000...1010 = 10

    c = 1000...0101 = -5 - 原码
        1111...1010 = - 反码
        1111...1011 = - 补码

    d = 1111...0110 - 补码
        1111...0101 - 反码
        1000...1010 - 原码 = -10

*/
void Test04()
{
    int a = 5;
    int c = -5;
    int b = a << 1;
    int d = c << 1;
    printf("%d\n", b);//10
    printf("%d\n", d);//-10
}

/*
Test05():
    & - 按2进制位与
    a = 0000...0011
    b = 0000...0101
    c = 0000...0001 = 1
*/
void Test05()
{
    int a = 3;
    int b = 5;
    int c = a&b;
    printf("%d ", c);//1
}

/*
Test06():
    | - 按2进制位或
    a = 0000...0011
    b = 0000...0101
    c = 0000...0111 = 7
*/
void Test06()
{
    int a = 3;
    int b = 5;
    int c = a|b;
    printf("%d ", c);//7
}

/*
Test07():
    ^ - 按2进制位异或
    相同为0，相异为1
    a = 0000...0011
    b = 0000...0101
    c = 0000...0110 = 6
*/
void Test07()
{
    int a = 3;
    int b = 5;
    int c = a^b;
    printf("%d ", c);//6
}

/*
Test08():
    不创建临时变量实现a和b值的交换
*/
void Test08_S1()
{
    int a = 3;//011
    int b = 5;//101
    printf("Before: a=%d,b=%d\n", a, b);
    a = a^b;//a = 011 ^ 101 = 110 = 6
    b = a^b;//b = 110 ^ 101 = 011 = 3
    a = a^b;//a = 110 ^ 011 = 101 = 5
    printf("After: a=%d,b=%d\n", a, b);
}
void Test08_S2()
{
    int a = 3;
    int b = 5;
    printf("Before: a=%d,b=%d\n", a, b); 
    a = a+b; //8
    b = a-b; //3
    a = a-b; //5
    printf("After: a=%d,b=%d\n", a, b);
}

/*
Test09():
    统计num的补码有几个1

    32bit
    (num>>i)&1 == 1 count++
*/
void Test09()
{
    int num = 0;
    while (1)
    {
        int count = 0;
        scanf("%d", &num);//-1
        int i =0;
        for (i = 0; i < 8*sizeof(num); i++)
        {
            if(1==((num>>i)&1))
            {
                count++;
            }
        }
        printf("%d\n", count);
    }
}

/*
    复合赋值符： += -= *= /= %= >>= <<= &= |= ^=
        a = a+2;
        a += 2;

        a = a>>1;
        a >>=1;

        a = a&1;
        a &=1;

    双目操作符 a+b
    单目操作符 !a, -, +, &, sizeof, *, ~, ++, --, 

    int a = 10;
    int* p = &a;//取地址操作符
    *p = 20;//解引用操作符

Test10():
    任何类型的指针变量都是占用4个字节。 
    指针即为地址，指针几个字节跟语言无关，而是跟系统的寻址能力有关，
    譬如以前是16为地址，指针即为2个字节，现在一般是32位系统，
    所以是4个字节，以后64位，则就为8个字节
*/
void Test10()
{
    int a = 10;
    char c = 'r';
    char* p = &c;
    int arr[10]={0};
    printf("%lu\n", sizeof(a));//4
    printf("%lu\n", sizeof(int));//4

    printf("%lu\n", sizeof(c));//1
    printf("%lu\n", sizeof(char));//1

    printf("%lu\n", sizeof(p));//8
    printf("%lu\n", sizeof(char*));//8

    printf("%lu\n", sizeof(arr));//40
    printf("%lu\n", sizeof(int[10]));//40
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
    //Test08_S1();
    //Test08_S2();
    //Test09();
    Test10();
    return 0;
}

