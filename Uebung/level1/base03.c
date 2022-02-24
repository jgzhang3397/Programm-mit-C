#include<stdio.h>

/*
Test01():
    描述
        输入一个十六进制数a，和一个八进制数b，输出a+b的十进制结果（范围-231~231-1）。
    输入描述：
        一行，一个十六进制数a，和一个八进制数b，中间间隔一个空格。
    输出描述：
        一行，a+b的十进制结果。

    示例1
        输入：
            0x12 05
        输出：
            23
    
    备注：
        十六进制Hexadecimal一般以0x开头，例如0xFF。八进制Octal，一般以0开头，例如07。
*/
void Test01()
{
    int a, b, result;
    scanf("%x %o", &a, &b);
    result = a + b;
    printf("%d\n", result);
}

/*
Test02():
    描述
        给定一个浮点数，要求得到该浮点数的个位数。

    数据范围： 0 < n <= 200 

    输入描述：
        一行，包括一个浮点数。
    输出描述：
        一行，包含一个整数，为输入浮点数对应的个位数。
    
    示例1
        输入：
            13.141
        输出：
            3
*/
void Test02()
{
    float f = 0.0;
    scanf("%f", &f);
    int n = (int)f;
    if(0< n && n < 200)
    {
        printf("%d\n", n%10);
    }
    else
    {
        printf("Error\n");
    }
}

/*
Test03():
    描述
        给定两个整数a和b (0 < a,b < 10,000)，计算a除以b的整数商和余数。
    输入描述：
        一行，包括两个整数a和b，依次为被除数和除数（不为零），中间用空格隔开。
    输出描述：
        一行，包含两个整数，依次为整数商和余数，中间用一个空格隔开。

    示例1
        输入：
            15 2
        输出：
            7 1
*/
#include<assert.h>

void Test03()
{
    int a = 1;
    int b = 1;
    int ret1 = 0;
    int ret2 = 0;
    assert(0<a && a<10000);
    assert(0<b && b<10000);
    scanf("%d %d", &a, &b);
    ret1 = a/b;
    ret2 = a%b;
    printf("%d %d", ret1, ret2);

}

/*
Test04():
    描述
        给定秒数 seconds ，把秒转化成小时、分钟和秒。

    数据范围： 0 < seconds < 100000000
    输入描述：
        一行，包括一个整数，即给定的秒数。
    输出描述：
        一行，包含三个整数，依次为输入整数对应的小时数、分钟数和秒数（可能为零），中间用一个空格隔开。

    示例1
        输入：
            3661
        输出：
            1 1 1
*/
void Test04()
{
    int secs = 0;
    int hour = 0;
    int mins = 0;
    int s = 0;
    scanf("%d", &secs);

    hour = secs / 3600;
    mins = secs % 3600 / 60;
    s = secs % 60;

    printf("%d %d %d\n", hour, mins, s);
}

/*
Test05():
    描述
        不使用累计乘法的基础上，通过移位运算（<<）实现2的n次方的计算。

    数据范围：0 \le n \le 31 \0≤n≤31 
    输入描述：
        一行输入整数n（0 <= n < 31）。
    输出描述：
        输出对应的2的n次方的结果。
    
    示例1
        输入：
            2
        输出：
            4

    在2进制中，2的表示为00000010
    我们只使用移位符来完成2的n次方，仅需使这个1往左移动。
    如4：00000100；8：00001000
*/
void Test05()
{
    int n = 0;
    int ret = 0;
    scanf("%d", &n);
    ret = 2 << (n-1);
    printf("%d\n", ret);
}
int main()
{
    //Test01();
    //Test02();
    //Test03();
    //Test04();
    Test05();
    return 0;
}