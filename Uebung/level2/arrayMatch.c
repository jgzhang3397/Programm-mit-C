/*
描述
牛牛刚学会数组不久，他拿到两个数组 a 和 b，询问 b 的哪一段连续子数组之和与数组 a 之和最接近。
如果有多个子数组之和同样接近，输出起始点最靠左的数组。

输入描述：
第一行输入两个正整数 n 和 m ，表示数组 a 和 b 的长度。
第二第三行输入 n 个和 m 个正整数，表示数组中 a 和 b 的值。

输出描述：
输出子数组之和最接近 a 的子数组

示例1

输入：
    2 6
    30 39 
    15 29 42 1 44 1
输出：
    29 42
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int max(int a, int b)
{
    return (a>=b?a:b);
}
void arrayMatch(int m, int suma, int sumb, int pb[m])
{
    int i, j;
    int flag = max(suma, sumb);
    int l, r;//left right
    int t;
    int temp;

    for(i=0; i<m; i++)
    {
        temp = 0;
        for(j=i; j<m; j++)
        {
            temp += pb[j];
            if(temp==suma)//直接输出对应的i,j的数组
            {
                for(t=i; t<=j; t++)
                {
                    printf("%d ", pb[t]);
                }
                break;
            }
            else if(temp<suma)
            {
                if(suma-temp<flag)
                {
                    l = i;//记录此子数组的开始点l和结束点r
                    r = j;
                    flag = suma - temp;// flag 会随着i，j的变化逐渐变小，通过flag 找到 对应的 i和j
                }
            }
            else
            {
                if(temp-suma<flag)
                {
                    l = i;//记录此子数组的开始点l和结束点r
                    r = j;
                    flag = temp - suma;// flag 会随着i，j的变化逐渐变小，通过flag 找到 对应的 i和j
                }
            }
        }
    }
    for(i=l; i<=r; i++)
    {
        printf("%d ", pb[i]);
    }
    
}
int main()
{
    int n, m;
    int i;
    scanf("%d %d", &n, &m);

    int suma=0, sumb=0;

    int * pa = (int *)malloc(n*sizeof(int));
    int * pb = (int *)malloc(m*sizeof(int));

    for(i=0; i<n; i++)
    {
        scanf("%d", (pa+i));
        suma += *(pa+i);
    }

    for(i=0; i<m; i++)
    {
        scanf("%d", (pb+i));
        sumb += *(pb+i);
    }

    arrayMatch(m, suma, sumb, pb);

    free(pa);
    pa = NULL;
    free(pb);
    pb = NULL;
    return 0;
}