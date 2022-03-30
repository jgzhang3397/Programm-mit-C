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
Test02():
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
int main()
{
    //Test01();
    Test02();
    return 0;
}