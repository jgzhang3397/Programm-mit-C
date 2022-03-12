#include<stdio.h>
#include<assert.h>
/*
Test01():
    描述
    试计算在区间1 到n 的所有整数中，数字x（0 ≤ x ≤ 9）共出现了多少次？
    例如，在1到11 中，即在1、2、3、4、5、6、7、8、9、10、11 中，数字1 出现了4 次。

    输入描述：
    输入共1行，包含2个整数n、x，之间用一个空格隔开。

    输出描述：
    输出共1行，包含一个整数，表示x出现的次数。

    示例1
        输入：
            11 1
        输出：
            4
*/
int times(int n, int x)
{
    int count = 0;
    while (n)
    {
        int temp = n % 10;
        if(temp == x)
            count ++;
        n /= 10;
    }
    return count;  
}
void Test01()
{
    int i, n, x;
    assert(0<=x && x<=9);
    int sum = 0;
    scanf("%d %d", &n, &x);
    
    for(i= 1; i<=n; i++)
    {
        sum += times(i, x);
    }
    printf("%d\n", sum);
}

/*
Test02():
    描述
    输入n个成绩，换行输出n个成绩中最高分数和最低分数的差。

    输入描述：
    两行，第一行为n，表示n个成绩，不会大于10000。使用malloc动态开辟内存
    第二行为n个成绩（整数表示，范围0~100），以空格隔开。

    输出描述：
    一行，输出n个成绩中最高分数和最低分数的差。

    示例1
    输入：
        10
        98 100 99 97 95 99 98 97 96 100
    输出：
        5
*/
#include<stdlib.h>
void Test02()
{
    int i, n;
    int min=100;
    int max=0;
    while (scanf("%d", &n)!=EOF && (1<=n && n<=10000))
    {
        int* score = (int *) malloc(n * sizeof(int));
        if(NULL == score)
        {
            fprintf(stderr, "memory allocation failed!\n");
            exit(0);
        }
        
        for(i=0; i<n; i++)
        {
            scanf("%d", score+i);//score+i == &score[i]
            max = max > score[i] ? max : score[i];
            min = min < score[i] ? min : score[i];
        }

        printf("%d\n", max - min);
        free(score);
        score = NULL;
    }
    
}

/*
Test03():
    描述
    期中考试开始了，大家都想取得好成绩，争夺前五名。从键盘输入 n 个学生成绩，输出每组排在前五高的成绩。

    数据范围：5≤n≤50  ，成绩采取百分制并不会出现负数

    输入描述：
    两行，第一行输入一个整数，表示n个学生（>=5），第二行输入n个学生成绩（整数表示，范围0~100），用空格分隔。

    输出描述：
    一行，输出成绩最高的前五个，用空格分隔。

    输入：
        6
        99 45 78 67 72 88
    输出：
        99 88 78 72 67
*/

void Test03_S1()
{
    int n,i,j,k;
    scanf("%d",&n);

    int* date=(int *)malloc(sizeof(int)*(n+1));//输入的n来决定数组大小，PS：指针和数组是等价的

    for(i=1;i<=n;i++)
        scanf("%d",&date[i]);//输入成绩

    for(i=0;i<5;i++)//寻找5次
    {
        date[0]=0;//用date[0]来存放最大值
        for(j=1;j<=n;j++)
        {
            if(date[j]>date[0])//如果此时的数大于date[0]，则更新date[0]
            {
                date[0]=date[j];
                k=j;//记录最大值的数组下标
            }
        }
        date[k]=0;//将原最大值改为0，避免下次再次输出。
        printf("%d ",date[0]);
    }
    free(date);
    date = NULL;
}

void Swap(int* p , int n) //冒泡排序
{
    int h = 1; //用于判断是否已经有序，如果是则跳出循环不必继续执行
    for(int i=1; i<=n; i++)
    {
        if (0 == h)
        {
            break;
        }
        else
        {
            h = 0;
        }
         
        for(int j=0; j<n - i; j++)
        {
            int temp = 0;
            if(*(p+j) < *(p+j+1))
            {
                // *(p+j) ^= *(p+j+1);
                // *(p+j+1) ^= *(p+j);
                // *(p+j) ^= *(p+j+1);
                temp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = temp;
                h = 1;
            }
        }
    }
}

void Test03_S2()
{
    int* p = NULL;
    int n;
    scanf("%d" , &n);
    p = malloc(n*sizeof(int)); //使用malloc（）可以开辟任意大小空间
    for(int i = 0;i < n; i++)
    {
        scanf("%d" ,p + i);
    }
    Swap(p , n);
    for(int i = 0;i < 5; i++)
    {
        printf("%d " , *(p + i) );
    }
    free(p); //释放堆空间
    p = NULL;
}
int main(void)
{
    //Test01();
    //Test02();
    //Test03_S1();
    Test03_S2();
    
}