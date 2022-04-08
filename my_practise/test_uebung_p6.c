#include<stdio.h>

// int main()
// {
//     int aa[2][5] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//     int *ptr1 = (int *)(&aa + 1);//&aa 是数组首元素地址 + 1 跳过这个数组
//     int *ptr2 = (int *)(*(aa + 1));//*(aa + 1) ==> aa[1] 第二行首元素地址
//     printf("%d, %d\n", *(ptr1 - 1), *(ptr2 -1));// 1, 6
//     return 0;
// }

/*
题目要求：
    旋转字符串：
        实现一个函数，可以左旋字符串中的k个字符
        例如：
            ABCD左旋一个字符： BCDA
            ABCD左旋二个字符： CDAB
*/

#include<assert.h>
#include<string.h>
// //1. 暴力求解法
// void left_move(char* arr, int k)
// {
//     assert(arr);
//     int i = 0;
//     int len = strlen(arr);
//     assert(k <= arr);
//     for ( i = 0; i < k; i++)
//     {
//         //左旋一个字符
//         char temp = *arr;
//         int j = 0;
//         for(j = 0; j<len-1; j++)
//         {
//             *(arr+j) = *(arr + j + 1);
//         }
//         *(arr + len - 1) = temp;
//     }
    
// }

//2. 三步翻转法
//ab cdef == 左边逆序 ==》ba cdef
//ba cdef == 右边逆序 ==》ba fedc
//ba fedc == 整体逆序 ==》cdefab
void reserve(char* left, char* right)
{
    while (left < right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    
}
void left_move(char* arr, int k)
{
    assert(arr);
    int len = strlen(arr);
    assert(k <= len);
    reserve(arr, arr+k-1);//左边逆序
    reserve(arr+k, arr+len-1);//右边逆序
    reserve(arr, arr+len-1);//整体逆序
}

// int main()
// {
//     char arr[] = "abcdef";
//     left_move(arr, 4);
//     printf("%s\n", arr);
//     return 0;
// }

/*
判断字符串arr2 是否是 arr1  旋转后的字符串，如果是yes，不是no
*/
int is_left_move(char* arr1, char* arr2)
{
    assert(arr1 != NULL);
    assert(arr2 != NULL);
    int len = strlen(arr1);
    int i = 0;
    for ( i = 0; i < len; i++)
    {
        left_move(arr1, 1);
        int ret = strcmp(arr1, arr2);
        if(ret == 0)
            return 1;
    }
    return 0;
    
}
int main()
{
    char arr1[] = "abcdef";
    char arr2[] = "efabcd";

    int ret = is_left_move(arr1, arr2);
    if(ret == 1)
        printf("yes\n");
    else
        printf("no\n");
}