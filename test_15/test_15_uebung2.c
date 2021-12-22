#include<stdio.h>
// //9*9 Table
// void print_table(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <=i; j++)
//         {
//            printf("%d*%d=%-3d ", i, j, i*j); 
//         }  
//         printf("\n");
//     }
    
// }
// int main()
// {
//     int n = 0;
//     scanf("%d", &n);
//     print_table(n);
//     return 0;
// }

//reverse_string(char* string), 将其字符反向排序
// #include<string.h>
// int my_strlen(char* arr)
// {
//     int count = 0;
//     while (*arr !='\0')
//     {
//         count++;
//         arr++;
//     }
//     return count;
// }
// void reverse_string(char* arr)
// {
//     int left = 0;
//     int right = my_strlen(arr)-1;
//     while (left<right)
//     {
//         char temp = arr[left];
//         arr[left] = arr[right];
//         arr[right]= temp;
//         left++;
//         right--;
//     }
// }
//mit Rekursion
// void reverse_string(char arr[])
// {
//     char temp = arr[0];
//     int len = my_strlen(arr);
//     arr[0] = arr[len-1];
//     arr[len-1]='\0';
//     if(my_strlen(arr+1)>=2)
//     {
//         reverse_string(arr+1);
//     }
//     arr[len-1]=temp;
// }
// int main()
// {
//     char arr[]="abcedfg";
//     reverse_string(arr);
//     printf("%s\n", arr);
//     return 0;
// }

//DigitSum(1729) = 1+7+2+9
//1729%10....9
//172%10...2
//17%10..7
//..
// int DigitSum(unsigned int num)
// {
//     if(num>9)
//     {
//         return DigitSum(num/10)+num%10;
//     }
//     else
//     {
//         return num;
//     }
// }
// int main()
// {
//     unsigned int num = 0;
//     scanf("%d", &num);
//     int ret = DigitSum(num);
//     printf("ret = %d\n", ret);
//     return 0;
// }

//实现n的k次方
double Pow(int n, int k)
{
    if(k<0)
    {
        return (1.0/(Pow(n, -k)));
    }
    else if(k==0)
    {
        return 1;
    }
    else
    {
        return n*Pow(n, k-1);
    }
}
int main()
{
    int n = 0;
    int k = 0;
    scanf("%d%d", &n, &k);
    double ret = Pow(n,k);
    printf("ret = %lf\n", ret);
}