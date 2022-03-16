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

void Swap_Test03(int* p , int n) //冒泡排序
{
    //一定进行N-1轮比较
    for(int i=0; i<=n-1; i++)
    {
        //用于判断是否已经有序，如果是则跳出循环不必继续执行
        // 0 == false; 1 == true
        int h = 1; 

        ////每一轮比较前n-1-i个，即已排序好的最后i个不用比较
        for(int j=0; j<n-1-i; j++)
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
                h = 0;
            }
        }

        if(h==1)
            break;
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
    Swap_Test03(p , n);
    for(int i = 0;i < 5; i++)
    {
        printf("%d " , *(p + i) );
    }
    free(p); //释放堆空间
    p = NULL;
}

/*
Test04():
描述
    输入两个升序排列的序列，将两个序列合并为一个有序序列并输出。
    数据范围： 1≤n,m≤1000  ， 序列中的值满足 0≤val≤30000 

输入描述：
    输入包含三行，
        第一行包含两个正整数n, m，用空格分隔。n表示第二行第一个升序序列中数字的个数，m表示第三行第二个升序序列中数字的个数。
        第二行包含n个整数，用空格分隔。
        第三行包含m个整数，用空格分隔。         
输出描述：
    输出为一行，输出长度为n+m的升序序列，即长度为n的升序序列和长度为m的升序序列中的元素
    输入：
        5 6
        1 3 7 9 22
        2 8 10 17 33 44
    输出：
        1 2 3 7 8 9 10 17 22 33 44
*/
void swap_Test04(int * p, int n)
{
    int i,j;
    for(i=0; i<n-1; i++)
    {
        int flag = 1;
        
        for(j=0; j<n-1-i; j++)
        {
            int temp = 0;
            if(*(p+j) > *(p+j+1))
            {
                temp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = temp;
                flag = 0;
            }
        }
        
        if(flag==1)
            break;
    }
}

void Test04()
{
    int i, n, m;
    while(scanf("%d %d", &n, &m)!=EOF && (1<=n && n<=1000)&&(1<=m && m<=1000))
    {
        int * arrNM = (int *)malloc((n+m)*sizeof(int));
        
        for(i=0; i<n; i++)
        {
            scanf("%d", arrNM + i);
        }
        for(i=n; i<(n+m); i++)
        {
            scanf("%d", arrNM + i);
        }
        
        swap_Test04(arrNM, (n+m));
        
        for(i = 0; i<(n+m); i++)
            printf("%d ", *(arrNM+i));
        free(arrNM);
        arrNM = NULL;
    }
}

/*
Test05():
    描述
    输入一个整数序列，判断是否是有序序列，有序，指序列中的整数从小到大排序或者从大到小排序(相同元素也视为有序)。
    数据范围： 3≤n≤50  序列中的值都满足 1≤val≤100 

    输入描述：
        第一行输入一个整数N(3≤N≤50)。
        第二行输入N个整数，用空格分隔N个整数。
    输出描述：
    输出为一行，如果序列有序输出sorted，否则输出unsorted。

    输入：
        5
        1 6 9 22 30
    输出：
        sorted
    
    输入：
        5
        3 4 7 2 10
    输出：
        unsorted
*/

int swap_Test05(int* p, int n)
{
    int i;
    int countPlus = 0;
    int countMinus = 0;
    for(i=0; i<n-1; i++)
    {
        while(*(p+i)<=*(p+i+1))
        {
            countPlus++;
            break;
        }
        while(*(p+i)>=*(p+i+1))
        {
            countMinus++;
            break;
        }
    }
    if(countPlus == (n-1) || countMinus ==(n-1))
        return 1;
    else
        return 0;
}

void Test05()
{
    int i,n;
    int* p = NULL;
    while(scanf("%d", &n)!=EOF && (3<=n && n<=50))
    {
        p = (int *)malloc(n*sizeof(int));
        for(i=0; i<n; i++)
        {
            scanf("%d", p+i);
        }
        int result = swap_Test05(p, n);
        if(result == 1)
            printf("sorted\n");
        else
            printf("unsorted\n");
        
        free(p);
        p= NULL;
    }
}
int main(void)
{
    //Test01();
    //Test02();
    //Test03_S1();
    //Test03_S2();
    //Test04();
    Test05();
    
}