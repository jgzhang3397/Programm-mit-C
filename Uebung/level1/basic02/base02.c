#include<stdio.h>

/*
Test01()
    描述
        输入一个字符，用它构造一个边长为5的三角形圣诞树。

    数据范围：保证输入的字符是一个 char 类型的值
    输入描述：
        输入只有一行，一个字符。
    输出描述：
        该字符构成的三角形圣诞树。

    1           -- 4个空格 + 1
   1 1          -- 3个空格 + 1
  1 1 1         -- 2个空格 + 1
 1 1 1 1        -- 1个空格 + 1
1 1 1 1 1       -- 没有空格
*/

void Test01()
{
    char cr = 0;
    scanf("%c", &cr);
    int i = 1; //记行数用的
    int j, g;  //j是输出“空格”用的，g是输出“字符+空格”用的
    int num = 5; //行数
    for ( i = 1; i <=num; i++)//关于行数i在前5行执行的循环（包括第5行）
    {
        for ( j = num - i; j > 0; j--)//输出第n行的前5-n个空格（n<=5）
        {
            printf(" ");
        }
        for ( g = 0; g < i; g++)//打印字符
        {
            printf("%c ", cr);
        }
        printf("\n");
    }
}

/*
Test02()
    转换以下ASCII码为对应字符并输出他们。
    73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116 , 33
*/
void Test02()
{
    char ch[] = {73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33};
    int i = 0;
    int sz = sizeof(ch)/sizeof(ch[0]);
    for (i = 0; i < sz; i++)
    {
        printf("%c", ch[i]);
    }
    printf("\n");
}

/*
Test03()
    输入一个人的出生日期（包括年月日），将该生日中的年、月、日分别输出。

    数据范围：年份满足 1990 ~ 2015，月份满足1~12  ，日满足 1~30
    输入描述：
        输入只有一行，出生日期，包括年月日，年月日之间的数字没有分隔符。
    输出描述：
        三行，第一行为出生年份，第二行为出生月份，第三行为出生日期。输出时如果月份或天数为1位数，需要在1位数前面补0。

    示例：
        输入：20130225 
        输出：
            year=2013
            month=02
            date=25
*/
void Test03()
{
    int brith;
    scanf("%d", &brith);
    int year = brith/10000;
    int month = brith%10000/100;
    int days = brith%100;
    while (1990<=year && year<=2015 && 1<=month && month<=12 && 1<=days && days<=30) 
    {
        printf("year=%d\n", year);
        if(month>=10)
        {
            printf("month=%d\n", month);
        }
        else
        {
            printf("month=0%d\n", month);
        }
        if(days>10)
        {
            printf("date=%d\n", days);
        }
        else
        {
            printf("date=0%d\n", days);
        }
        break;
    }
}

/*
Test04()
    描述:
    将一个四位数，反向输出。
    输入描述：
        一行，输入一个整数n（1000 <= n <= 9999）。
    输出描述：
        针对每组输入，反向输出对应四位数。

    示列:
        输入：1234
        输出：4321
*/
void Test04()
{
    char ch[10];
    scanf("%s", ch);
    for (int i = 3; i >=0; i--)
    {
        printf("%c", ch[i]);
    }
}

/*
Test05()
    问题：KiKi今年5岁了，已经能够认识100以内的非负整数，并且并且能够进行 100 以内的非负整数的加法计算。
     不过，BoBo老师发现KiKi在进行大于等于100的正整数的计算时，规则如下：

    1.只保留该数的最后两位，例如：对KiKi来说1234等价于34；

    2.如果计算结果大于等于 100， 那么KIKI也仅保留计算结果的最后两位，如果此两位中十位为0，则只保留个位。

    例如：45+80 = 25
    
    数据范围：0 < a, b < 2^31 -1

    要求给定非负整数 a和 b，模拟KiKi的运算规则计算出 a+b 的值。

    输入描述：
        一行，输入两个非负整数a和b，用一个空格分隔。（0 <= a,b<= 2^31-1）。

    输出描述：
        针对每组输入，输出按照KiKi的运算规则计算出 a+b 的值。

    示例：
        输入： 45 80
        输出： 25
*/
void Test05()
{
    unsigned int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", (a+b)%100);
}

/*
Test06()
    描述:
    给定一个浮点数，要求得到该浮点数的个位数。

    数据范围： 
        0 <= n <= 200
    输入描述：
        一行，包括一个浮点数。
    输出描述：
        一行，包含一个整数，为输入浮点数对应的个位数。
    示例：
    输入：3.14
    输出：3
*/
void Test06()
{
    float a;
    scanf("%f", &a);
    int n = (int)a;
    if(0<= n && n <= 200)
    {
        printf("%d\n", n%10);
    }
    else
    {
        printf("Error\n");
    }
}

/*
Test07()
    描述
    问题：一年约有 3.156×10^7 s，要求输入您的年龄，显示该年龄合多少秒。

    数据范围： 0 < age <=200

    输入描述：
        一行，包括一个整数age
    输出描述：
        一行，包含一个整数，输出年龄对应的秒数。
*/
#include<math.h>
void Test07()
{
    long int age, second;
    scanf("%ld", &age);
    //second = age * 3.156e7;
    second = age * 3.156 * pow(10, 7);
    printf("%ld", second);
}

/*
Test08()
    描述:   
    依次输入一个学生的3科成绩，在屏幕上输出该学生的总成绩以及平均成绩。
    输入描述：
        一行，3科成绩，成绩之间用一个空格隔开。
    输出描述：
        一行，总成绩和平均成绩（小数点后保留两位），用一个空格隔开。
    示例：
        输入：79.5 80.0 98.0
        输出：257.50 85.83
*/
void Test08()
{
    float a, b, c, sum, avg;
    scanf("%f %f %f", &a, &b, &c);
    sum = a + b + c;
    avg = sum/3.0;
    printf("%.2f %.2f", sum, avg);
}

/*
Test09()
    输入描述：
        输入一个char类型字符
    输出描述：
        输出一个用这个字符填充的对角线长5个字符，倾斜放置的菱形
    输入： 
        #
    输出：
          #
         ###
        #####
         ###
          #
*/
void Test09()
{
    char c = 0;
    scanf("%c", &c);
    int i,j;
    int n = 3;
    
    //打印上三角 三行
    for (i = 1; i <=n; i++)
    {
        //打印空格
        for(j = 0; j< n - i; j++)
        {
            printf(" ");
        }
        //打印符号
        for(j = 0; j<2*i-1; j++)
        {
            printf("%c", c);
        }
        printf("\n");
    }

    //打印下三角 两行
    for ( i = 1; i < n; i++)
    {
        //打印空格
        for(j = 0; j< i; j++)
        {
            printf(" ");
        }
        //打印符号
        for(j = 0; j<2*(n-i)-1; j++)
        {
            printf("%c", c);
        }
        printf("\n");
    }  
}

/*
Test10()
    描述
    实现字母的大小写转换。多组输入输出。
        输入描述：
            多组输入，每一行输入大写字母。
        输出描述：
            针对每组输入输出对应的小写字母。
    
    输入： A
          B
    
    输出： a
          b

    In ASCII:
    A->Z ==> 65 -> 90
    a->z ==> 97 -> 122
    相差32

    int getchar ( void );
        Returns the next character from the standard input (stdin).
    int putchar ( int character );
        Writes a character to the standard output (stdout).
    */
void Test10_1()
{
    char a = 0;
    while(scanf("%c", &a)!=EOF)
    {
        printf("%c\n", a+32);
        getchar();
    }
}
void Test10()
{
    int ch = 0;
    while ((ch = getchar()) != EOF)
    {
        getchar();//防止回车被读取，可在其前面多读取一次消耗回车
        if(65<=ch && ch <= 90)
        {
            putchar(ch + 32);//输入大写，输出小写
            printf("\n");
        }
        else
        {
            putchar(ch - 32);//输入小写，输出大写
            printf("\n");
        }
    }
    
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
    //Test10();
    Test10_1();
    return 0;
}