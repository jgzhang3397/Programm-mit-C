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

int main()
{
    //Test01();
    //Test02();
    //Test03();
    //Test04();
    Test05();
    return 0;
}