#include<stdio.h>

/*
Test01()
    输入描述：
        输入一个整数，范围在32位有符号整数范围内

    输出描述：
        输出这个整数

    示例：
        输入： 3
        输出： 3
*/

void Test01()
{
    int a = 0;
    scanf("%d", &a);
    printf("%d\n", a);
}

/*
Test02()
    输入描述：
        输入一个浮点数
    输出描述：
        输出一个浮点数，保留三位小数

    示例：
        输入：1.359578
        输出：1.360
*/
void Test02()
{
    double a = 0.00;
    scanf("%lf", &a);
    printf("%.3f\n", a);

}

/*
Test03()
    输入描述：
        输入一个字符，范围在ascii范围内
    输出描述：
        输出这个字符 
    示例：
        输入： a
        输出： a   
*/
void Test03()
{
    char a = 0;
    scanf("%c", &a);
    printf("%c\n", a);
}

/*
Test04()
    输入描述：
        一行输入 3 个整数，用空格隔开。
    输出描述：
        请输出第二个整数的值。
    
    输入： 1 2 3
    输出： 2

*/
void Test04()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", b);
}

/*
Test05()
    输入描述：
        一行读入一个 char 类型的字符。
    输出描述：
        输出这个字符组成的 3*3 矩形。
    输入：#
    输出：
        ###
        ###
        ###

*/
void Test05()
{
    char c = 0;
    scanf("%c", &c);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    
}

/*
Test06()
    输入描述：
        随机输入的浮点数
    输出描述：
        四舍五入之后的整数
    
    示例：
        输入： 14.99
        输出： 15
*/
void Test06()
{
    double d = 0.00;
    scanf("%lf", &d);

    int a = (int)d;//强转

    //正
    if (d >=0)
    {
        if(d + 0.5 >= a + 1.0)
            printf("%d\n", a+1);
        else
            printf("%d\n", a);
    }

    //负
    if(d < 0)
    {
        if(d - 0.5 <= a - 1.0)
            printf("%d\n", a-1);
        else
            printf("%d\n", a);
    }
}

/*
Test07();
    描述
    BoBo写了一个十六进制整数ABCDEF，他问KiKi对应的十进制整数是多少。

    输入描述：
            无
    输出描述：
            十六进制整数ABCDEF对应的十进制整数，所占域宽为15。
    
    备注：
        printf可以使用使用格式控制串“%md”输出域宽为m的十进制整数。
*/
void Test07()
{
    int a = 0xABCDEF;
    printf("%15d\n", a);
}

/*
Test08();
    请输出十进制整数1234对应的八进制和十六进制。

    输入描述：
        无
    输出描述：
        十进制整数1234对应的八进制和十六进制（字母大写），用空格分开，并且要求，在八进制前显示前导0，在十六进制数前显示前导0X。
    备注：
    printf可以使用使用格式控制串“%o”、“%X”分别输出八进制整数和十六进制整数，并使用修饰符“#”控制前导显示
*/
void Test08()
{
    int a = 1234;
    printf("%#o %#X\n", a, a);
}

/*
Test09()
    输入描述：
        读入一个字符，一个整数，一个单精度浮点数用换行符隔开，
    输出描述：
        按顺序输出字符、整数、单精度浮点数，用空格分隔，浮点数保留 6 位小数
    
    示例：
        输入：
                a
                1
                1.23
        输出：
                a 1 1.230000
*/
void Test09()
{
    char a;
    int i;
    float f;
    scanf("%c %d %f", &a, &i, &f);
    printf("%c %d %.6f\n", a, i, f);
}

/*
Test10()
    描述
        读入 3 个整数，牛牛尝试以后两个数字占 8 个空格的宽度靠右对齐输出。
    输入描述：
        输入三个整数，用空格隔开。
    输出描述：
        输出 3 个整数以每个数字占 8 个空格靠右对齐输出
    
    示例：
        输入：
        2 7 5
        输出：
        2       7       5
*/
void Test10()
{
    int i1, i2, i3;
    scanf("%d %d %d", &i1, &i2, &i3);
    printf("%d%8d%8d\n", i1, i2, i3);
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
    Test10();
    return 0;
}