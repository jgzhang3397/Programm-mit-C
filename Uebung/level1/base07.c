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

/*
Test06():
    描述
    有一个有序数字序列，从小到大排序，将一个新输入的数插入到序列中，保证插入新数后，序列仍然是升序。

    输入描述：
    第一行输入一个整数N(0≤N≤50)。

    第二行输入N个升序排列的整数，输入用空格分隔的N个整数。

    第三行输入想要进行插入的一个整数。

    输出描述：
    输出为一行，N+1个有序排列的整数。

    示例1
        输入：  
        5
        1 6 9 22 30
        8
        输出：
        1 6 8 9 22 30
*/
void insert_int(int* p, int n, int m)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        if(m < *(p+i) )//定位插入位置
        {
            for(j=n; j>i; j--)//后面全都往后窜一位
            {
                *(p+j) = *(p+j-1);
            }
            *(p+i) = m;//第i位放插入数m
            break;
        }
        *(p+n) = m; //要插入的值比所有原数组中所元素都大，放在末尾
    }
}

void my_print(int* p, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ", *(p+i));
    }
    printf("\n");
}

void Test06()
{
    int n, i, m;
    int* p = NULL;
    while(scanf("%d", &n)!=EOF && (0<=n && n<= 50))
    {
        p = (int *)malloc((n+1)*sizeof(int));
        for(i=0; i<n; i++)
        {
            scanf("%d", p+i);
        }
        scanf("%d", &m);
        insert_int(p, n, m);
        my_print(p, n+1);

        free(p);
        p = NULL;
    }
}

/*
Test07():
    描述
    有一个整数序列（可能有重复的整数），现删除指定的某一个整数，输出删除指定数字之后的序列，序列中未被删除数字的前后位置没有发生改变。

    数据范围：序列长度和序列中的值都满足 1≤n≤50

    输入描述：
    第一行输入一个整数(0≤N≤50)。

    第二行输入N个整数，输入用空格分隔的N个整数。

    第三行输入想要进行删除的一个整数。

    输出描述：
    输出为一行，删除指定数字之后的序列。

    示例1
        输入：
            7
            1 2 3 4 4 5 9
            4
        输出：
            1 2 3 5 9
*/

void print(int * ps, int count)
{
    int i;
    for(i=0; i<count; i++)//创建count长度的数组，没有和m相等的元素
    {
        printf("%d ", *(ps+i));
    }
    printf("\n");
}
void delete_num(int * ps, int n, int m)
{
    int i, count=0;
    for(i=0; i<n; i++)
    {
        if(*(ps+i)!=m)//如果不是要删除的那个元素，则数组正常遍历，如果找到了，就覆盖
        {
            *(ps+count) = *(ps+i);
            count++;
        }
    }
    print(ps, count);  
}

void Test07()
{
    int n, i, m;
    int * ps = NULL;
    while(scanf("%d", &n)!=EOF && (1<=n && n<=50))
    {
        ps = (int *)malloc(n*sizeof(int));
        for(i=0; i<n; i++)
        {
            scanf("%d", ps+i);
        }
        scanf("%d", &m);
        delete_num(ps, n, m);

        free(ps);
        ps = NULL;
    }
}

/*
Test08():
    描述
    输入n个整数的序列，要求对这个序列进行去重操作。
    所谓去重，是指对这个序列中每个重复出现的整数，
    只保留该数第一次出现的位置，删除其余位置。

    输入描述：
    输入包含两行，第一行包含一个正整数n（1 ≤ n ≤ 1000），
    表示第二行序列中数字的个数；第二行包含n个整数（范围1~5000），用空格分隔。

    输出描述：
    输出为一行，按照输入的顺序输出去重之后的数字，用空格分隔。

    示例1
    输入：
    5
    10 12 93 12 75
    输出：
    10 12 93 75
*/
void delete_repeat_num(int* ps, int n)
{
    int i, j, flag=1;
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<i; j++)
        {
            if(*(ps+j)==*(ps+i))
                flag = 0;
        }
        if(flag)
            printf("%d ", *(ps+i));
        flag = 1;
    }
    printf("\n");
}

void Test08()
{
    int i,n;
    int* ps = NULL;
    while(scanf("%d", &n)!=EOF && (1<=n && n<=5000))
    {
        ps = (int *)malloc(n*sizeof(int));
        for(i=0; i<n; i++)
        {
            scanf("%d", ps+i);
        }
        delete_repeat_num(ps, n);
        
        free(ps);
        ps = NULL;
    }
}

/*
Test09():
    描述
    用筛选法求n以内的素数。筛选法求解过程为：将2~n之间的正整数放在数组内存储，
    将数组中2之后的所有能被2整除的数清0，再将3之后的所有能被3整除的数清0 ，
    以此类推，直到n为止。数组中不为0 的数即为素数。

    输入描述：
    多组输入，每行输入一个正整数（不大于100）。

    输出描述：
    针对每行输入的整数n，输出两行，第一行，输出n之内（包括n）的素数，用空格分隔，

    第二行，输出数组中2之后被清0 的个数。每行输出后换行。

    i = 2; ps+i = 4
*/

void get_prime_num(int * ps, int n)
{
    int i, j, count=0;
    for(i=0; i<n-1; i++)
    {
        *(ps+i) = i+2;//将2～n放在数组内

        for(j = 2; j<*(ps+i); j++)
        {
            if(*(ps+i)%j == 0)
            {
                *(ps+i) = 0;
                break;//此处的作用在于：减少递归，即数组元素被2～n任意整除都不为素数，所以可以break直接终止循环
            }
        }
    }
    
    for(i = 0; i<n-1; i++)
    {
        if(*(ps+i)!=0)
            printf("%d ", *(ps+i));
        else
            count++;
    }
    printf("\n%d\n", count);
}

void Test09()
{
    int n;
    int * ps = NULL;
    while(scanf("%d", &n)!=EOF && (1<=n && n<=100))
    {
        ps = (int *)malloc(n*sizeof(int));
        get_prime_num(ps, n);

        free(ps);
        ps = NULL;
    }
}
int main(void)
{
    //Test01();
    //Test02();
    //Test03_S1();
    //Test03_S2();
    //Test04();
    //Test05();
    //Test06();
    //Test07();
    //Test08();
    Test09();
    
}