/*
Test
    描述
    给你一个整数n，输出n∗n的蛇形矩阵。
    输入描述：
    输入一行，包含一个整数n
    输出描述：
    输出n行，每行包含n个正整数，通过空格分隔。 1<=n<=1000

    示例1
    输入：
    4
    输出：
    1 2 6 7
    3 5 8 13
    4 9 12 14
    10 11 15 16

    void * memset ( void * ptr, int value, size_t num );
        将 ptr 指向的内存块的 前 num 个字节设置为指定值value（解释为无符号字符）。

        Value to be set. The value is passed as an int, 
        but the function fills the block of memory using the unsigned char conversion of this value.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void right(int**p,int*x,int*y,int*i,int n);//右
void lower_left(int**p,int*x,int*y,int*i,int n);//左下
void upper_right(int**p,int*x,int*y,int*i,int n);//右上
void lower(int**p,int*x,int*y,int*i,int n);//下

void start(int**p,int n)
{
    int x=0,y=0, i=1;
    p[x][y]=i;
    i++;
    right(p,&x,&y,&i,n);
}
void right(int**p,int*x,int*y,int*i,int n)//右
{
    if((*i)<=n*n)
    {
        (*y)++;
        p[*x][*y]=(*i);
        (*i)++;
        if((*x)==0)
            lower_left(p,x,y,i,n);//左下
        else if((*x)==(n-1))
            upper_right(p,x,y,i,n);//右上
    }
}
void lower_left(int**p,int*x,int*y,int*i,int n)//左下
{
    if((*i)<=n*n)
    {
        while(((*y)>0)&&((*x)!=(n-1)))
        {
            (*y)--;
            (*x)++;
            p[*x][*y]=(*i);
            (*i)++;
        }
        if((*x)!=(n-1))
            lower(p,x,y,i,n);//下
        else if((*x)==(n-1))
            right(p,x,y,i,n);//右
    }
}
void upper_right(int**p,int*x,int*y,int*i,int n)//右上
{
     if((*i)<=n*n)
    {
        while(((*x)>0)&&(*y)!=(n-1))
        {
            (*y)++;
            (*x)--;
            p[*x][*y]=(*i);
            (*i)++;
        }
        if(((*x)==0)&&((*y)<n-1))
            right(p,x,y,i,n);//右
        else if((*y)==(n-1))
            lower(p,x,y,i,n);//下
    }
}
void lower(int**p,int*x,int*y,int*i,int n)//下
{
    if((*i)<=n*n)
    {
        (*x)++;
        p[*x][*y]=(*i);
        (*i)++;
        if((*y)==0)
            upper_right(p,x,y,i,n);//右上
        else if((*y)==(n-1))
            lower_left(p,x,y,i,n);//左下
    }
}
int main()
{
    int n=0,m=0,sum=0;
    scanf("%d",&n);
    int**p=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    {
        p[i]=malloc(n*sizeof(int));
        memset(p[i],0,sizeof(int));
    }
    start(p,n);
    
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n;k++)
        {
            printf("%d ",p[i][k]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++)
    {
        free(p[i]);
        p[i]=NULL;
    }
    free(p);
    p=NULL;
    return 0;
}
