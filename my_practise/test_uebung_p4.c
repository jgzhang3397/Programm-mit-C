#include<stdio.h>
/*
结构体
*/

/*
题目1:
*/
// struct S
// {
//     int a;
//     int b;
// };
// int main()
// {
//     struct S a, *p = &a;
//     a.a = 99;
//     printf("%d\n", a.a);
//     printf("%d\n", p->a);
//     //printf("%d\n", *p.a);//.的优先级大于* 需要()
//     printf("%d\n", (*p).a);
//     return 0;
// }

/*
题目2:
*/
// struct stu
// {
//     int num;
//     char name[10];
//     int age;
// };
// void fun(struct stu *p)
// {
//     printf("%s\n", (*p).name);
//     return;
// }
// int main()
// {
//     struct stu students[3] = { {9801, "zhang", 20},
//                             {9901, "wang",21},
//                             {9802, "wu", 23}
//                             };
//     fun(students + 1);//wang
//     return 0;
// }

/*
题目3:喝汽水
    1瓶汽水1元，2个空瓶可以买一瓶
    20元 多少瓶？
*/
// int main()
// {
//     int money = 0;
//     int total = 0;
//     int empty = 0;
//     scanf("%d", &money);
//     // //买回来的汽水
//     // total = money;
//     // empty = money;
//     // //换回来的汽水
//     // while (empty>=2)
//     // {
//     //     total += empty/2;
//     //     empty = empty/2 + empty%2;
//     // }

//     //loesung2:
//     //一个瓶子= 0.5
//     if (money >= 1)
//     {
//         total = 2*money -1;
//     }
    
//     printf("Total = : %d\n", total);
//     return 0;
// }

/*
简单题：声明一个指向char类型变量的指针p，p的值不可修改，但p指向的变量值可修改
    char* const p
*/

/*
题目：
    定义一个方法：调整数组中的数值，奇数在前面，偶数在后面
*/
void print(int *arr, int sz)
{
    int i = 0;
    for ( i = 0; i < sz; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n"); 
}
void move(int arr[], int sz)
{
    int left = 0;
    int right = sz - 1;
    while (left<right)
    {
        //从左边找偶数
        while (arr[left]%2 == 1)
        {
            left ++;
        }
        //从右边找奇数
        while (arr[right]%2 == 0)
        {
            right --;
        }
        if(left < right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    
}
int main()
{
    int arr[] = {2, 4, 6, 8, 10, 1, 3, 5, 7};
    int sz = sizeof(arr)/sizeof(arr[0]);
    move(arr, sz);
    print(arr, sz);
    return 0;
}

/*
简答题：大端，小端
    大端：大端字节序把数据的高字节内容存放到低地址，低字节内容存放到高地址
    小端：小端字节序把数据的低字节内容存放到低地址，高字节内容存放到高地址
*/
