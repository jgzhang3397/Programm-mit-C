#include<stdio.h>

/*
题目名称：杨氏矩阵
题目内容：
    有一个数字矩阵，矩阵的每一行从左到右是递增的，矩阵从上到下是递增的，请编写程序查找在此矩阵中某个数字是否存在
    题目要求：时间复杂度小于O(N);-->不能遍历数组，O(N)表示遍历整个数组
示例：
1 2 3
4 5 6
7 8 9

解析：找到右上角元素arr[x][y]， k大于它划行，k小于它划列
*/

int findNum(int arr[3][3], int k, int* px, int* py)
{
    int x = 0;
    int y = *py - 1;
    while (x<=*px-1 && y>= 0)
    {
        //找到了
        if(k>arr[x][y])
        {
            x++;
        }
        else if (k<arr[x][y])
        {
            y--;
        }
        else
        {
            *px = x;
            *py = y;
            return 1;
        }
    }
    //没找到
    return 0;
}
int main()
{
    int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int k = 7;
    int x = 3;
    int y = 3;

    //返回行参数
    int ret = findNum(arr, k, &x, &y);
    if(ret == 1)
    {
        puts("找到了");
        printf("x= %d, y= %d\n", x, y);
    }
    else
    {
        puts("没找到");
    }
    return 0;
}