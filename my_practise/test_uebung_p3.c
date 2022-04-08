#include<stdio.h>

// int main()
// {
//     unsigned long pulArray[] = {6, 7, 8, 9, 10};
//     unsigned long *pulPtr;

//     pulPtr = pulArray;//首元素6地址
//     *(pulPtr + 3) += 3;// ==> pulArray[3] += 3 ==> 9 + 3 == 12

//     printf("%d, %d\n", *pulPtr, *(pulPtr + 3));//6, 12
//     return 0;
// }

/*
    写一个函数逆序字符串内容
*/
// #include<string.h>
// #include<assert.h>
// void string_reserve(char* str)
// {
//     assert(str != NULL);//保证指针str的有效性

//     int len = strlen(str);
//     char* left = str;
//     char* right = str + len -1;

//     while (left < right)
//     {
//         char temp = *left;//不能用char* temp，因为他指向地址， *left是首元素并不是首元素地址
//         *left = *right;
//         *right = temp;
//         left++;
//         right--;
//     }
    
// }
// int main()
// {
//     char arr[256] = { 0 };
//     //scanf("%s", arr);//abcd ==> dcba// scanf读取到空格结束
//     gets(arr);//读取一行
//     string_reserve(arr);
//     printf("%s\n", arr);
//     return 0;
// }

/*
题目：
    求sum = a + aa + aaa + aaaa + aaaaa + ...的和，其中a 是个数字
    例如： 2 + 22 + 222 + 2222 + 22222
*/
// int main()
// {
//     int a = 0;
//     int n = 0;
//     scanf("%d%d", &a, &n);
//     int sum = 0;
//     int i = 0;
//     int ret = 0;
//     //2 22 222 2222 22222
//     for ( i = 0; i < n; i++)
//     {
//         ret = ret * 10 + a;
//         sum += ret;
//     }
//     printf("%d\n", sum);
//     return 0;
// }

/*
打印1到10000之间的水仙花数
*/
// #include<math.h>
// int main()
// {
//     int i = 0;
//     for ( i = 0; i < 10000; i++)
//     {
//         //判断i是否为水仙花数（自幂数）
//         //1. 计算i的个位数 -n位数
//         int n = 1;
//         // while (i /= 10)
//         // {
//         //     n++;
//         // } //避免i的值受到影响,添加一个temp 变量等于 i
//         int temp = i;
//         int sum = 0;
//         while (temp /= 10)
//         {
//             n++;
//         }
//         //2.计算i的每一位的n次方之和 sum
//         temp = i;//123
//         while (temp)
//         {
//             sum += pow(temp % 10, n);
//             temp /= 10;
//         }
//         //3. 比较i == sum
//         if(i == sum)
//         {
//             printf("%d\n", i);
//         }
        
//     }
    
// }

/*
题目：
    打印棱形：
            *
           ***
          *****
         *******
        *********
       ***********
      *************
       ***********
        *********
         *******
          *****
           ***
            *
*/
int main()
{
    int line = 0;
    scanf("%d", &line);//line = 7
    //打印上半部分
    int i = 1;
    for ( i = 1; i <=line; i++)
    {
        //打印空格
        int j = 1;
        for ( j = 1; j <=line - i; j++)//6行空格
        {
            printf(" ");
        }
        //打印*
        for ( j = 1; j <=2*i -1 ; j++)
        {
            printf("*");
        }
        printf("\n");   
    }
    //打印下半部分
    for ( i = 1; i <= line-1; i++)
    {
        //打印空格
        int j = 1;
        for(j = 1; j <=i; j++)
        {
            printf(" ");
        }
        //打印*
        for(j = 1; j <=2*(line - i) -1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
