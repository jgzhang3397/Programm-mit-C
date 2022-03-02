#include<stdio.h>
#define MaxSize 10

typedef struct 
{
    int data[MaxSize];//用静态的“数组”存放数据元素
    int length;//顺序表的当前长度
}SqList;//顺序表的类型定义

void InitInsert(SqList &L)
{
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = 0;
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

void ListInsert(SqList &L, int i, int e)
{
    for (int j = L.length; j>=i; j--)
    {
       L.data[j] = L.data[j - 1];
    }
    L.data[i-1] = e;
    L.length++;
    
}
int main()
{
    SqList L; //声明一个顺序表
    InitInsert(L); //初始化顺序表
    ListInsert(L, 3, 3);
    printf("%d\n", L.data[2]);
    return 0;
}