#include<stdio.h>
/*
Test01():
    9*9 Table
*/
void print_table(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
           printf("%2d *%2d=%-3d ", i, j, i*j); 
        }  
        printf("\n");
    }   
}
void Test01()
{
    int n = 0;
    scanf("%d", &n);
    print_table(n);
}

/*
Test02():
    reverse_string(char* string), 将其字符反向排序
*/
#include<string.h>
int my_strlen(char* arr)
{
    int count = 0;
    while (*arr !='\0')
    {
        count++;
        arr++;
    }
    return count;
}
void reverse_string(char* arr)
{
    int left = 0;
    int right = my_strlen(arr)-1;
    while (left<right)
    {
        char temp = arr[left];
        arr[left] = arr[right];
        arr[right]= temp;
        left++;
        right--;
    }
}

void reverse_string_with_Rekursion(char arr[])
{
    char temp = arr[0];//取出对应数组的0位元素

    int len = my_strlen(arr);//数组长度，随着rekusion变化

    arr[0] = arr[len-1];//最后一位放在0位
    arr[len-1]='\0';

    if(my_strlen(arr+1)>=2)//数组长度小于2时不需要置换
    {
        reverse_string_with_Rekursion(arr+1);
    }

    arr[len-1]=temp;
}

void Test02()
{
    char arr[]="abcedfg";
    // reverse_string(arr);
    // printf("%s\n", arr);

    reverse_string_with_Rekursion(arr);
    printf("%s\n", arr);
}

/*
Test03():
    DigitSum(1729) = 1+7+2+9
    1729%10....9
    172%10...2
    17%10..7
    ..
*/
int DigitSum(unsigned int num)
{
    if(num>9)
    {
        return DigitSum(num/10)+num%10;
    }
    else
    {
        return num;
    }
}
void Test03()
{
    unsigned int num = 0;
    scanf("%d", &num);
    int ret = DigitSum(num);
    printf("ret = %d\n", ret);
}

/*
Test04():
    实现n的k次方
*/
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

void Test04()
{
    int n = 0;
    int k = 0;
    scanf("%d%d", &n, &k);
    double ret = Pow(n,k);
    printf("ret = %lf\n", ret);
}

int main()
{
    //Test01();
    Test02();
    //Test03();
    //Test04();
    return 0;
}