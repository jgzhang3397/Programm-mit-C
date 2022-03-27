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

int main()
{
    Test01();
    return 0;
}