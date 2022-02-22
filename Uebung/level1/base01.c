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
int main()
{
    //Test01();
    //Test02();
    //Test03();
    //Test04();
    Test05();
    return 0;
}