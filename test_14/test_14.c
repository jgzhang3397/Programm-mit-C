#include<stdio.h>

// int main()
// {
//     int a = 5/2;//2
//     int b = 5%2;//1
//     printf("%d\n", a);
//     printf("%d\n", b);
//     return 0;
// }

// int main()
// {
//     int a = 16;
//     //>> -- bedeutet bewegen zu rechts
//     //die binar bewegen
//     //00000000000000000000000000010000 == 16
//     //右移操作符
//     //1.算术右移
//     //  右边丢弃，左边补原符号位。
//     //2.逻辑右移
//     //  右边丢弃，左边补零
//     int b = a >> 1;
//     printf("%d ", b);
//     return 0;
// }

// int main()
// {
//     int a = -1;
//     //
//     //整数的binar表示有，原码， 反码， 补码
//     //储存到内存的是补码
//     //100000000000000000000001 - 原码
//     //111111111111111111111110 - 反码，符号位不变，其他取反
//     //111111111111111111111111 - 补码，反码加一
//     //正整数的原反补是相同的，所以16可以直接移动
//     int b = a >> 1;
//     printf("%d ", b);
//     return 0;
// }

// int main()
// {
//     int a = 5;
//     int b = a << 1;
//     //左移操作符
//     //左边丢弃，右边补0
//     //000000000000000000101
//     printf("%d ", b);
//     return 0;
// }

// int main()
// {
//     //& - 按2进制位与
//     int a = 3;
//     int b = 5;
//     int c = a&b;
//     //0000...000011
//     //0000...000101
//     printf("%d ", c);//1
//     return 0;
// }

// int main()
// {
//     //| - 按2进制位或
//     int a = 3;
//     int b = 5;
//     int c = a|b;
//     //0000...000011
//     //0000...000101
//     printf("%d ", c);//0000...000111 = 7
//     return 0;
// }

// int main()
// {
//     //^ - 按2进制位异或
//     //相同为0，相异为1
//     int a = 3;
//     int b = 5;
//     int c = a^b;
//     //0000...000011
//     //0000...000101
//     printf("%d ", c);//0000...000110 = 6
//     return 0;
// }

// //不创建临时变量实现a和b值的交换
// int main()
// {
//     int a = 3;
//     int b = 5;
//     printf("Before: a=%d,b=%d\n", a, b);
//         // int temp = 0;
//         // printf("Before: a=%d,b=%n", a, b);
//         // temp = a;
//         // a = b;
//         // b = temp;
//         // printf("After: a=%d,b=%d\n", a, b);
//     //Loesung 1
//     // a = a+b; //8
//     // b = a-b; //3
//     // a = a-b; //5
//     //Loesung 2
//     //a = 011
//     //b = 101
//     a = a^b;//a = 110 = 6
//     b = a^b;//b = 011 = 3
//     a = a^b;//a = 101 = 5
//     printf("After: a=%d,b=%d\n", a, b);
//     return 0;
// }

// //统计num的补码有几个1
// int main()
// {
//     int num = 0;
//     while (1)
//     {
//         int count = 0;
//         scanf("%d", &num);//-1
//         //32bit
//         //num&1 ==1
//         //00000000000000000000000000000011
//         //00000000000000000000000000000001
//         //00000000000000000000000000000001
//         int i =0;
//         for (i = 0; i < 8*sizeof(num); i++)
//         {
//             if(1==((num>>i)&1))
//             {
//                 count++;
//             }
//         }
        
//             // while (num)
//             // {
//             //     if(num % 2 ==1)
//             //     {
//             //         count++;
//             //         num = num /2;
//             //     }
//             // }
//         printf("%d\n", count);
//     }
//     return 0;
// }

// int main()
// {
//     int a = 1;
//     //beide sind identisch
//     a = a+2;
//     a += 2;

//     a = a>>1;
//     a >>=1;

//     a = a&1;
//     a &=1;
//     //复合赋值符： += -= *= /= %= >>= <<= &= |= ^=
//     return 0;
// }

//双目操作符 z.B. a+b
//单目操作符 z.B. !a, -, +, &, sizeof, *, ~, ++, --, 
// int main()
// {
//     int a = 10;
//     int* p = &a;//取地址操作符
//     *p = 20;//解引用操作符
//     return 0;
// }

int main()
{
    int a = 10;
    char c = 'r';
    char* p = &c;
    int arr[10]={0};
    printf("%d\n", sizeof(a));//4
    printf("%d\n", sizeof(int));

    printf("%d\n", sizeof(c));//1
    printf("%d\n", sizeof(char));

    printf("%d\n", sizeof(p));//4 or 8
    printf("%d\n", sizeof(char*));

    printf("%d\n", sizeof(arr));//40
    printf("%d\n", sizeof(int[10]));
}
