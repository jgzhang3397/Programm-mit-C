#include<stdio.h>
#include<assert.h>
#include<math.h>
/*
描述
现在给出一个素数，这个素数满足两点：

1、  只由1-9组成，并且每个数只出现一次，如13,23,1289。

2、  位数从高到低为递减或递增，如2459，87631。

请你判断一下，这个素数的回文数是否为素数（13的回文数是131,127的回文数是12721）。

输入描述：
输入只有1行。
第1行输入一个整数t，保证t为素数。
数据保证：9<t<109
输出描述：
输出一行字符串，如果t的回文数仍是素数，则输出“prime”，否则输出"noprime"。

输入：
    13
输出：
    prime
说明：
    13的回文数是131，131是素数
*/
int is_prime(long long n)
{
    int i;
    int flag = 0;
    for(i=2; i<(int)sqrt((long long)n); i++)
    {
        if(n%i==0)
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
int main()
{
    int n;
    scanf("%d", &n);
    assert(n>9);
    int arr[20];
    int i = 0;
    int k, j;
    int e;
    int flag = 0;
    long long palinNum = 0;
    while(n)
    {
        e = n%10;
        arr[i] = e;
        i++;
        n /= 10;   
    }
    i--;
    //判断是否是素数
    if(arr[1]-arr[0]>0)
    {
        for(k=1; k<=i; k++)
        {
            if(arr[k]<=arr[k-1])
            {
                flag = 1;
                break;
            }
        }
    }
    else if(arr[1]-arr[0]<0)
    {
        for(k=1; k<=i; k++)
        {
            if(arr[k]>=arr[k-1])
            {
                flag = 1;
                break;
            }
        }
    }
    else
    {
        flag = 1;
    }
    
    if(flag == 0)
    {
        
        for(j=1; j<=i; j++)
        {
            arr[i+j] = arr[j];
        }
        arr[i] = arr[0];

        for(j=0; j<=i; j++)
        {
            arr[i-j] = arr[i+j];
        }
        
        
        for(j=0; j<=2*i; j++)
        {
            palinNum += (long long) arr[j]*(long long)pow((int)10,(int)(2*i-j));
        }
    }
    
    int result = is_prime(palinNum);
    if(result == 1)
        printf("noprime\n");
    else
        printf("prime\n");
    return 0;
}