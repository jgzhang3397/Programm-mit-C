#include<stdio.h>
/*
Test01();
    描述
    KiKi得到了两个n行m列的矩阵，他想知道两个矩阵是否相等，请你回答他。(当两个矩阵对应数组元素都相等时两个矩阵相等)。

    输入描述：
    第一行包含两个整数n和m，表示两个矩阵包含n行m列，用空格分隔。

    从2到n+1行，每行输入m个整数（范围-231~231-1），用空格分隔，共输入n*m个数，表示第一个矩阵中的元素。

    从n+2行到2n+1，每行输入m个整数（范围-231~231-1），用空格分隔，共输入n*m个数，表示第二个矩阵中的元素。
    1 < n,m < 10

    输出描述：
    一行，如果两个矩阵相等输出"Yes"并换行，否则输出"No"并换行。

    示例1
    输入：
        2 2
        1 2
        3 4
        1 2
        3 4
    输出：
        Yes
*/
void Test01()
{
    int n, m;
    int i,j;
    int arr1[10][10];
    int arr2[10][10];
    int flag = 1;
    while(scanf("%d%d", &n, &m)!=EOF &&(1<n && n<10) &&(1<m && m<10))
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                scanf("%d", &arr1[i][j]);
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                scanf("%d", &arr2[i][j]);
                if(arr1[i][j]!=arr2[i][j])
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 0)
            printf("No\n");
        else
            printf("Yes\n");
    }
}

/*
Test02()
    描述
    给你一个整数n，按要求输出n∗n的回型矩阵
    输入描述：
    输入一行，包含一个整数n

    1<=n<=19
    输出描述：
    输出n行，每行包含n个正整数.

    示例1
    输入：
        4
    输出：
        1  2  3  4
        12 13 14 5
        11 16 15 6
        10  9  8 7
*/

void Test02()
{
    int n;
    scanf("%d", &n);
    int arr[19][19] = {0};
    int x = 0, y = 0;
    int a = n, b = 0;//a==上界左界、b==下界右界
    int i, j;
    int flag = 1;

    for(i=1; i<=n*n; i++)
    {
        arr[x][y] = i;
        if(flag == 1)//往右走
            y++;
        else if(flag == 2)//往下走
            x++;
        else if(flag == 3)//往左走
            y--;
        else if(flag == 4)//往右走
            x--;

        if(y == (a-1) && x==b)//碰到右界,开始往下走
            flag = 2;
        else if(y == (a-1) && x == (a-1))//碰到下界,开始往左走
            flag = 3;
        else if(y == b && x == (a-1))//碰到左界,开始往上走,一圈完
            flag = 4;
        else if(y==b && x==(b+1))//碰到上界,开始往右走
        {
            flag = 1;
            b++;
            a--;
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main(void)
{
    //Test01();
    Test02();
}