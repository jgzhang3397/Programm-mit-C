#include<stdio.h>
/*
Test01():
    描述
    国王将金币作为工资，发放给忠诚的骑士。第一天，骑士收到一枚金币；
    之后两天（第二天和第三天），每天收到两枚金币；之后三天（第四、五、六天），
    每天收到三枚金币；之后四天（第七、八、九、十天），
    每天收到四枚金币……；这种工资发放模式会一直这样延续下去：
    当连续N天每天收到N枚金币后，骑士会在之后的连续N+1天里，每天收到N+1枚金币。
    请计算在前K天里，骑士一共获得了多少金币。

    输入描述：
    输入只有1行，包含一个正整数K，表示发放金币的天数。
    输出描述：
    输出只有1行，包含一个正整数，即骑士收到的金币数。

    示例1
        输入：
            6
        输出：
            14
*/
void Test01()
{
    int k;
    int i = 1;
    int result = 0;
    scanf("%d", &k);
    while(k>0)
    {
        if(k >= i)
            result += i*i;
        else
            result += k*i;
        k -= i;
        i++;  
    }
    printf("%d\n", result);
}

/*
Test02()&Test03():
    描述
    今天牛牛学到了回文串，他想在数字里面找回文，即回文数，回文数是正着读与倒着读都一样的数，
    比如1221，343是回文数，433不是回文数。请输出不超过n的回文数。

    输入描述：
    输入一个整数n(1 <= n <= 100000)
    输出描述：
    从1开始按从小到大的顺序输出所有回文数
*/

void fun_Test02(int i)
{
    //初始化
    int arr[5] = {0};
    int k = 0;
    int mid = 0;
    int j = 0;

    //得到这个数的每一位的数存到arr数组中
    int t = i;
    while (t)
    {
        arr[k] = t%10;
        t /=10;
        k++;
    }

    //判断k是奇数还是偶数,找到数组中位元素的下标
    mid = (k-1) / 2;
    if(k % 2 == 1)
    {
        while (j<=mid)
        {
            if(arr[mid-j] == arr[mid+j])
                j++;
            else
                break;
        }
        if(j>mid)
            printf("%d\n", i);
    }
    else
    {
        while (j<=mid)
        {
            if(arr[mid-j] == arr[mid+j+1])
                j++;
            else
                break;
        }
        if(j>mid)
            printf("%d\n", i);
    } 
}
void Test02()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++)
    {
        fun_Test02(i);
    }
}

void fun_Test03(int num)
{
    int arr[5], n, i, j;
    n = num;
    for (i = 0; i < 5; i++) {
        arr[i] = n % 10; 
        n = n / 10;
        if (n == 0) { break; }
    }
    for (j = 0; j < i ; j++) {
        if (arr[j] != arr[i - j]) { return; }
    }
    printf("%d \n", num);
}
void Test03()
{
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <=n; i++) {
        fun_Test03(i);
    }
}

/*
Test04():
    描述
    KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的带空格直角三角形图案。

    输入描述：
    多组输入，一个整数（2~20），表示直角三角形直角边的长度，即“*”的数量，也表示输出行数。

    输出描述：
    针对每行输入，输出用“*”组成的对应长度的直角三角形，每个“*”后面有一个空格。

    示例1

    输入：
    5
    输出：
            * 
          * * 
        * * * 
      * * * * 
    * * * * *
*/

void Test04()
{
    int n;
    int i, j, k;
    while(scanf("%d", &n)!=EOF)
    {
        for(i = 1; i<=n; i++)
        {
            //打印空格
            for(j=1; j<=(n-i); j++)
            {
                printf("  ");
            }
            
            //打印*
            if(j>(n-i))
            {
                for(k=1; k<=i; k++)
                {
                    printf("* ");
                }
            }
            printf("\n");     
        }
    }
}
void Test04_s2()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int i,j;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i+j>=n-1) printf("* ");
                else printf("  ");
            }
            printf("\n");
        }
    }
}

/*
Test05():
    KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的金字塔图案。
    输入描述：
    多组输入，一个整数（2~20），表示金字塔边的长度，即“*”的数量，，也表示输出行数。
    输出描述：
    针对每行输入，输出用“*”组成的金字塔，每个“*”后面有一个空格。

    示例1
输入：
4

输出：
   * 
  * * 
 * * * 
* * * * 
*/

void Test05()
{
    int n;
    while (scanf("%d", &n)!=EOF)
    {
        int i, j, k;
        for(i = 1; i<=n; i++)
        {
            //打印空格
            for(j = 1; j<=n-i; j++)
            {
                printf(" ");
            }

            //打印*
            if(j>n-i)
            {
                for(k=1; k<=i; k++)
                {
                    printf("* ");
                }
            }

            //换行
            printf("\n");
        }
    }
    
}
int main()
{
    //Test01();
    //Test02();
    //Test03();
    //Test04();
    //Test04_s2();
    Test05();
    return 0;
}