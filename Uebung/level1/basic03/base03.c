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

    数据范围：0≤n≤31 
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

/*
Test06():
    描述
    输入n科成绩（浮点数表示），统计其中的最高分，最低分以及平均分。

    数据范围：1≤n≤100  ， 成绩使用百分制且不可能出现负数

    输入描述：
    两行，

    第1行，正整数n（1≤n≤100）

    第2行，n科成绩（范围0.0~100.0），用空格分隔。

    输出描述：
    输出一行，三个浮点数，分别表示，最高分，最低分以及平均分（小数点后保留2位），用空格分隔。

    示例1
        输入：
            5
            99.5 100.0 22.0 60.0 88.5
        输出：
            100.00 22.00 74.00
*/
void Test06()
{
    int n = 1;

    float max = 0;
    float min = 100;

    float sum = 0;
    float avg = 0;

    scanf("%d", &n);
    assert(1<= n && n<= 100);

    float score[100] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &score[i]);
        if(score[i]>= 0.00 && score[i]<= 100.00)
        {
            sum += score[i];

            if(score[i]>max)
                max = score[i];

            if(score[i]<min)
                min = score[i];
        }
        else
            return;
        
    }

    avg = sum/n;

    printf("%.2f %.2f %.2f\n", max, min, avg);  
    
}

/*
Test07():
    描述
    根据给出的三角形3条边a, b, c，计算三角形的周长和面积。

    数据范围： 0<a,b,c≤100000 

    输入描述：
    一行，三角形3条边（能构成三角形），中间用一个空格隔开。

    输出描述：
    一行，三角形周长和面积（保留两位小数），中间用一个空格隔开，输出具体格式详见输出样例。

    示例1
        输入：
        3 3 3

        输出：
        circumference=9.00 area=3.90
复制
*/
#include<math.h>
void Test07()
{
    //define input variables 
    float a, b, c, s;
    scanf("%f %f %f", &a, &b, &c);

    //判断能否构成三角形
    if(a<= 0 || b<= 0 || c<= 0)
    {
        printf("输入错误,请重新输入：>");
        return;
    }
    else
    {
        if( ((a+b)>c && fabs(a-b)<c) || ((b+c)>a && fabs(b-c)<a) || ((a+c)>b && fabs(a-c)<b))
        {
            float p = (a+b+c)/2;
            s = sqrt(p*(p-a)*(p-b)*(p-c));
            printf("circumference=%.2f area=%.2f\n", a + b + c, s);
        }
        else
        {
            printf("输入不构成三角形,请重新输入：>");
            return;
        }
    }

}

/*
Test09():
        描述
        输入一个浮点数f, 表示华氏温度, 输出对应的摄氏温度c , c=5/9*(f-32)

        输入描述：
        输入一个浮点数f(1 <= f<= 100000)

        输出描述：
        输出浮点数,保留3位小数
            示例1
                输入：
                100

                输出：
                37.778
*/
void Test09()
{
    double f, c;
    scanf("%lf", &f);//double ==> lf, float ==> f
    if(1<= f && f<= 100000)
    {
        c = 5.0/9.0*(f-32);//c=5/9*(f-32), 5/9 = 0
        printf("%.3f\n", c);
    }
    else
    {
        return;
    }

}

/*
Test10()
    描述
    牛牛口渴了，要喝10升水才能解渴，但现在只有一个深 h 厘米，底面半径是 r 厘米的水杯，牛牛最少要喝多少杯水才能解渴。

    水杯的体积公式是 pi * h * r^2  
    其中 pi 取 3.14 ，h和r是整数。

    输入描述：
    输入杯子的高度 h，底面半径 r。

    输出描述：
    输出牛牛最少要喝多少杯水
*/
#define PI 3.14
void Test10()
{
    int h, r;
    scanf("%d %d", &h, &r);

    int v = PI * h * pow(r, 2);

    int sum = 10000/v + 1;
    printf("%d", sum);
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