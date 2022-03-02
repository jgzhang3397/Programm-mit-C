#include<stdio.h>

/*
Test01():
    描述
    小乐乐比较懒惰，他现在想睡觉，然后再去学习。他知道现在的时刻，以及自己要睡的时长，想设定一个闹钟叫他起床学习，但是他太笨了，不知道应该把闹钟设定在哪个时刻，请你帮助他。(只考虑时和分，不考虑日期)

    输入描述：
    输入现在的时刻以及要睡的时长k（单位：minute），中间用空格分开。

    输入格式：hour:minute k(如hour或minute的值为1，输入为1，而不是01)

    (0 ≤ hour ≤ 23，0 ≤ minute ≤ 59，1 ≤ k ≤ 10^9)

    输出描述：
    对于每组输入，输出闹钟应该设定的时刻，输出格式为标准时刻表示法（即时和分都是由两位表示，位数不够用前导0补齐）。

    示例1
        输入：
            0:0 100
        输出：
            01:40
*/
void Test01()
{
    int hour, minute, mins;
    scanf("%d:%d %d", &hour, &minute, &mins);//"%d:%d %d"
    hour = (hour + (minute + mins)/60)%24;
    minute = (minute + mins)%60;
    printf("%02d:%02d\n", hour, minute);//%02d
}

/*
Test02():
    描述
    小乐乐最近在课上学习了如何求两个正整数的最大公约数与最小公倍数，但是他竟然不会求两个正整数的最大公约数与最小公倍数之和，请你帮助他解决这个问题。

    输入描述：
    每组输入包含两个正整数n和m。(1 ≤ n ≤ 109，1 ≤ m ≤ 109)

    输出描述：
    对于每组输入，输出一个正整数，为n和m的最大公约数与最小公倍数之和。

    示例1
        输入：
        10 20
        输出：
        30
    
    最小公倍数 = n * m / 最大公约数
*/
void Max(long long *n, long long *m)
{
    long long temp;
    if(*m>*n)
    {
        temp = *n;
        *n = *m;
        *m = temp;
    }
}

long long get_GCD(long long n, long long m)
{
    long long k;
    while ((k = n%m)!= 0)
    {
        n = m;
        m = k;
    }
    return m;
}

long long get_LCM(long long n, long long m)
{
    long long multi;
    multi = n * m;

    long long t = get_GCD(n, m);

    return multi/t;
}

void Test02()
{
    long long n, m, result;
    scanf("%lld %lld", &n, &m);

    Max(&n, &m);//较大值为n， 较小值为m

    long long a = get_GCD(n, m);//GCD : greatest common divisor
    long long b = get_LCM(n, m);//LCM : least common multiple

    printf("%lld\n", a+b);

}

/*
Test03():
    描述
    小乐乐喜欢数字，尤其喜欢0和1。他现在得到了一个数，想把每位的数变成0或1。
    如果某一位是奇数，就把它变成1，如果是偶数，那么就把它变成0。请你回答他最后得到的数是多少。

    输入描述：
    输入包含一个整数n (0 ≤ n ≤ 10^9)

    输出描述：
    输出一个整数，即小乐乐修改后得到的数字。

    示例1
        输入：
            222222
        输出：
            0
    示例2
        输入：
            123
        输出：
            101
*/
#include<math.h>
void Test03()
{
    int n;
    scanf("%d", &n);

    int result  = 0;
    int i = 0;
    while (n)
    {
        int w = n % 10;

        if(w % 2 == 0)
        {
            w = 0;
        }
        else
        {
            w = 1;
        }

        result += w * pow(10, i);
        i++;
        
        n /= 10;
    }  

    printf("%d\n", result);
}

/*
Test04():
    输入描述：
        第一行输入 x1 和 y1，用空格隔开。
        第二行输入 x2 和 y2，用空格隔开。
        其中 x1 ， y1 ，x2 ，y2 都是整数
    输出描述：
        输出线段的长度的平方
    
    示例1
        输入：
            1 1
            2 2
        输出：
            2
*/
void Test04()
{
    int x1, y1, x2, y2;
    scanf("%d %d", &x1, &y1);
    getchar();//读取回车'\n'
    scanf("%d %d", &x2, &y2);
    
    int sum = pow(((x1-x2)), 2) + pow((y1-y2), 2);
    printf("%d\n", sum);
}

/*
Test05():
    描述
        KiKi开始学习英文字母，BoBo老师告诉他，有五个字母A(a), E(e), I(i), O(o),U(u)称为元音，
        其他所有字母称为辅音，请帮他编写程序判断输入的字母是元音（Vowel）还是辅音（Consonant）。

    输入描述：
        多组输入，每行输入一个字母。

    输出描述：
        针对每组输入，输出为一行，如果输入字母是元音（包括大小写），输出“Vowel”，如果输入字母是非元音，输出“Consonant”。

    示例1
        输入：
            A
            b
        输出：
            Vowel
            Consonant
*/
void Test05()
{
    int i = 0;
    char input;
    char vowel[10] = {'A', 'a', 'E','e', 'I','i', 'O','o','U','u'};
    while (scanf("%c", &input) != EOF)
    {
        if(input != '\n')
        {
            for (i = 0; i < 10; i++)
            {
                if(input == vowel[i])
                {
                    printf("Vowel\n");
                    break;
                }
            }
            if(i == 10)
                printf("Consonant\n");
        }
        
    }
    
}

/*
Test06():
    气象意义上，通常以3～5月为春季(spring)，
    6～8月为夏季(summer)，9～11月为秋季(autumn)，
    12月～来年2月为冬季(winter)。请根据输入的年份以及月份，输出对应的季节。

    输入描述：
        输入的数据格式是固定的YYYYMM的形式，即：年份占4个数位，月份占2个数位。
    输出描述：
        输出月份对应的季节（用英文单词表示，全部用小写字母）。
    
    示例1
        输入：
            201901
        输出：
            winter
*/
void Test06()
{
    int x;
    
    scanf("%d", &x);
    int t = x%100;
    if(3 <= t && t <= 5)
        printf("spring\n");
    else if(6<= t && t <= 8)
        printf("summer\n");
    else if(9<= t && t <= 11)
        printf("autumn\n");
    else if(12==t || (t>=0 && t<3))
        printf("winter\n");
    else
        printf("enter error\n");

}

/*
Test07():
    描述
    小乐乐获得4个最大数，请帮他编程找到最大的数。

    输入描述：
        一行，4个整数，用空格分开。
    输出描述：
        一行，一个整数，为输入的4个整数中最大的整数。
    
    示例1
        输入：
            5 8 2 5
        输出：
            8
*/
void demo01_t7()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    int x = a>b?a:b;
    int y = c>d?c:d;

    int max = x>y?x:y;
     
    printf("%d\n", max);
}

void demo02_t7()
{
    int n, max = 0;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &n);
        if(n>max)
            max = n;
    }
    printf("%d\n", max);
    
}

void Test07()
{
    //demo01_t7();
    demo02_t7();
}

/*
Test08():
    描述
    牛牛从键盘输入一个整数，请你判断这个整数能被 2 3 7 中哪几个数整除，并按升序输出。
    如果不能被 2 3 7 任意一个数整除则输出 n。

    输入描述：
        输出一个整数
    输出描述：
        输出能被 2 3 7 哪几个数整除，并按升序输出。
*/
void demo01_t8()
{
    int n;
    scanf("%d", &n);
    if(n%2 == 0 && n %3 != 0 && n%7 != 0)
        printf("2\n");
    else if(n%2 != 0 && n %3 == 0 && n%7 != 0)
        printf("3\n");
    else if(n%2 != 0 && n %3 != 0 && n%7 == 0)
        printf("7\n");
    else if(n%(2*3)==0 && n%7 != 0)
        printf("2 3\n");
    else if(n%(2*7)==0 && n%3 != 0)
        printf("2 7\n");
    else if(n%(3*7)==0 && n%2 != 0)
        printf("3 7\n");
    else if(n%(2*3*7)==0)
        printf("2 3 7\n");
    else
        printf("n\n");
}

void demo02_t8()
{
    int n;
    scanf("%d", &n);
    if(n%2==0)
        printf("2 ");
    
    if(n%3==0)
        printf("3 ");
    
    if(n%7==0)
        printf("7\n");
    
    if(n%2!=0 && n%3!=0 && n%7!=0)
        printf("n\n");

}

void Test08()
{
    //demo01_t8();
    demo02_t8();
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
    Test08();
    return 0;
}