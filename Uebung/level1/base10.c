#include<stdio.h>
#include<math.h>

/*
Test01():
    描述
    牛牛刚刚学了素数的定义：素数值指在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数
    牛牛想知道在 [l,r] 范围内全部素数的和

    输入描述：
    输入两个正整数 l，r 表示闭区间范围

    输出描述：
    输出 [l,r] 范围内的素数的和

    示例1
        输入：
        2 6
        输出：
        10
*/
int get_prime_num(int n)
{
    int i;
    int flag = 0;
    int limit = (int)sqrt((double)n);
    for(i=2; i<=limit; i++)
    {
        if(n%i == 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        return n;
    else
        return 0;
}

void Test01()
{
    int l, r;
    scanf("%d %d", &l, &r);
    int i;
    int sum = 0;
    for(i=l; i<=r; i++)
    {
        sum += get_prime_num(i);
    }
    printf("%d\n", sum);
}

/*
Test02()& Test03():
    描述

若一个数（首位不为零）从左向右读与从右向左读都一样，我们就将其称之为回文数。

例如：给定一个10进制数56，将56加65（即把56从右向左读），得到121是一个回文数。
又如：对于10进制数87：
STEP1：87+78  = 165                  STEP2：165+561 = 726

STEP3：726+627 = 1353                STEP4：1353+3531 = 4884

在这里的一步是指进行了一次N进制的加法，上例最少用了4步得到回文数4884。

写一个程序，给定一个N（2<=N<=10或N=16）进制数M（100位之内），
求最少经过几步可以得到回文数。如果在30步以内（包含30步）不可能得到回文数，则输出“Impossible!”
进制N>10时，使用大写'A'字母表示10，'B'表示11,...,'E'表示16

输入描述：
两行，分别为N,M

示例1
输入：
    9
    87
输出：
    STEP=6
*/
#include<assert.h>
int sum_reserve_num(int m)
{
    int i =0, j=0;
    int arr[100];
    int reserve_num = 0;
    int k = m;
    while(k)
    {
        arr[i] = k%10;
        k /= 10;
        i ++;
    }
    for(j=0; j<i; j++)
    {
        reserve_num += arr[j]*(int)pow(10, (int)(i-j-1));
    }
    return (m+reserve_num);
}

int is_palinNum(int m)
{
    int i = 0, j=0;
    int arr[100];
    int left = 0;
    int right = 0;
    int flag = 0;
    while(m)
    {
        arr[i] = m%10;
        m /= 10;
        ++i;
    }
    right = i-1;
    while(left<right)
    {
        if(arr[left++]==arr[right--])
        {
            flag = 0;
        }
        else
        {
            flag = 1;
            break;
        }  
    }
    if(flag == 1)
        return 1;
    else
        return 0;
    
}
void Test02()
{
    int n, m;
    scanf("%d %d", &n, &m);
    assert(2<=n && n<=10 || n==16);
    int m_to_dec = 0;
    int i = 0;
    int e;
    int count = 0;
    while(m)
    {
        e = m % 10;
        m_to_dec += e * (int)pow((int)n, (int)i); 
        m /= 10;
        i++;
    }
    
    int flag = is_palinNum(m_to_dec);
    
    while(flag)
    {
        count++;
        m_to_dec = sum_reserve_num(m_to_dec);
        flag = is_palinNum(m_to_dec);
        if(count>=30)
            break;
    }
    if(count < 30)
        printf("STEP=%d\n", count);
    else
        printf("Impossible!\n");
}

//from other 
#include<string.h>
#include<stdbool.h>

bool judge(char* p, int n)
{
    for(int i=0;i<n/2;i++)
    {
        if(p[i]!=p[n-1-i])
            return false;
    }
    return true;
}
void STEP(char* M1, int len, int N)
{
    int m=0, n=0;
    char M2[100];
    char* p = M2;
    for(int i = 0; i<len; i++)
    {
        int n1, n2;
        if(M1[i]>='0' && M1[i]<='9')
            n1 = M1[i] - 48;//'0'的ascii == 48 表示1-10进制
        else
            n1 = M1[i] - 'A' +10;//进制N>10时，使用大写'A'字母表示10，'B'表示11,...,'E'表示16

        if(M1[len-i-1]>='0'&&M1[len-i-1]<='9')
            n2=M1[len-i-1]-48;
        else
            n2=M1[len-i-1]-'A'+10;

        n=n1+n2;//?

        if(m!=0)
            n++;
        m = n/N;
        n %= N;

        if(n<10)
            *p = (char)(n+48);
        else
            *p = 'A' + n - 10;

        p++;

        if(m==1)
            *p = (char)(m+48), p++;
        *p = '\0';

        int len2 = strlen(M2);
        for(int i=0;i<len2;i++)
        {
            M1[i]=M2[len2-1-i];
        }
        M1[len2]='\0';
    }
}
void Test03()
{
    int N, i;
    char M1[100];
    scanf("%d%s", &N, M1);
    int len = strlen(M1);
    for(i=0; i<31; i++)
    {
        STEP(M1, len, N);
        if(judge(M1, len))
            break;
    }
    if(i<31)
        printf("STEP=%d",i+1);
    else
        printf("Impossible!");
}

/*
Test04():
描述
世界上有10类人，1类是懂二进制的，另一类的不懂二进制的。牛牛是第10种人，因此他是懂二进制的。
牛牛把二进制数分成两种，一种是 1 的数量是偶数的，牛牛称之为 1 数，一种是 0 的数量是偶数的，
牛牛称之为 0 数，如果一个数同时是 1 数和 0 数，那称之为 10 数。
    输入描述：
    第一行输入一个正整数 n 表示数的个数
    第二行输入 n 个正整数，表示每个输入的数字    
    输出描述：
    输出一行，对每个数字进行分类，即输出 0 或 1 或 10，如果既不是 0 类也不是 1 类则输出 100

    示例1
        输入：
        2
        1 10
        输出：
        0 10

    <<左移运算符
    1.将一个运算对象的各二进制位全部左移若干位（左边的二进制丢弃，右边补0）
    11 << 2 = 44
    -14 <<2 =-56
    -14的二进制（11111111 11111111 11111111 11110010）左移2位 为
    11111111 11111111 11111111 11001000 结果为（-56）
【补充】：对于左移，直观的理解为，对于正数来说，左移相当于乘以2（但效率比乘法高）

    >>右移运算符
    将一个运算对象的各二进制位全部右移若干位，正数左补0，负数左补1.
    4 >> 2 = 1;//100
    -14 >> 2 = -4;
【补充】：对于右移，直观的理解为，对于正数来说，右1移相当于除以2（但效率比除法高）

*/

void Test04()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int x;
        int n0=0, n1=0;
        scanf("%d", &x);
        while(x)
        {
            if(x%2==0)
                n0++;
            else
                n1++;
            x >>= 1;
        }
        if (n0 % 2 == 0 && n1 % 2 == 0) printf("10 ");
        else if (n0 % 2 == 0) printf("0 ");
        else if (n1 % 2 == 0) printf("1 ");
        else printf("100 ");
    }
}
int main()
{
    //Test01();
    //Test02();
    //Test03();
    Test04();
    return 0;
}