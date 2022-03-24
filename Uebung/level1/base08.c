#include<stdio.h>
/*
Test01();
    描述
    KiKi得到了两个n行m列的矩阵，他想知道两个矩阵是否相等，请你回答他。(当两个矩阵对应数组元素都相等时两个矩阵相等)。

    输入描述：
    第一行包含两个整数n和m，表示两个矩阵包含n行m列，用空格分隔。

    从2到n+1行，每行输入m个整数（范围-231~231-1），用空格分隔，共输入n*m个数，表示第一个矩阵中的元素。

    从n+2行到2n+1，每行输入m个整数（范围-231~231-1），用空格分隔，共输入n*m个数，表示第二个矩阵中的元素。
    1 < n,m < 10

    输出描述：
    一行，如果两个矩阵相等输出"Yes"并换行，否则输出"No"并换行。

    示例1
    输入：
        2 2
        1 2
        3 4
        1 2
        3 4
    输出：
        Yes
*/
void Test01()
{
    int n, m;
    int i,j;
    int arr1[10][10];
    int arr2[10][10];
    int flag = 1;
    while(scanf("%d%d", &n, &m)!=EOF &&(1<n && n<10) &&(1<m && m<10))
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                scanf("%d", &arr1[i][j]);
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                scanf("%d", &arr2[i][j]);
                if(arr1[i][j]!=arr2[i][j])
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 0)
            printf("No\n");
        else
            printf("Yes\n");
    }
}

/*
Test02()
    描述
    给你一个整数n，按要求输出n∗n的回型矩阵
    输入描述：
    输入一行，包含一个整数n

    1<=n<=19
    输出描述：
    输出n行，每行包含n个正整数.

    示例1
    输入：
        4
    输出：
        1  2  3  4
        12 13 14 5
        11 16 15 6
        10  9  8 7
*/

void Test02()
{
    int n;
    scanf("%d", &n);
    int arr[19][19] = {0};
    int x = 0, y = 0;
    int a = n, b = 0;//a==上界左界、b==下界右界
    int i, j;
    int flag = 1;

    for(i=1; i<=n*n; i++)
    {
        arr[x][y] = i;
        if(flag == 1)//往右走
            y++;
        else if(flag == 2)//往下走
            x++;
        else if(flag == 3)//往左走
            y--;
        else if(flag == 4)//往右走
            x--;

        if(y == (a-1) && x==b)//碰到右界,开始往下走
            flag = 2;
        else if(y == (a-1) && x == (a-1))//碰到下界,开始往左走
            flag = 3;
        else if(y == b && x == (a-1))//碰到左界,开始往上走,一圈完
            flag = 4;
        else if(y==b && x==(b+1))//碰到上界,开始往右走
        {
            flag = 1;
            b++;
            a--;
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

/*
Test03():
    描述
    给出两幅相同大小的黑白图像（用0-1矩阵）表示，求它们的相似度。
    若两幅图像在相同位置上的像素点颜色相同，则称它们在该位置具有相同的像素点。
    两幅图像的相似度定义为相同像素点数占总像素点数的百分比。

    输入描述：
    第一行包含两个整数m和n，表示图像的行数和列数，用单个空格隔开。
    1≤m≤100, 1≤n≤100。之后m行，每行n个整数0或1，表示第一幅黑白图像上各像素点的颜色，
    相邻两个数用单个空格隔开。之后m行，每行n个整数0或1，表示第二幅黑白图像上各像素点的颜色，
    相邻两个数用单个空格隔开。
    输出描述：
    一个实数，表示相似度(以百分比的形式给出)，精确到小数点后两位。

    示例1
    输入：
        3 3
        1 0 1
        0 0 1
        1 1 0
        1 1 0
        0 0 1
        0 0 1
    输出：
        44.44
*/
#include<stdlib.h>
#include<string.h>
void init(int m, int n, int arr[m][n])
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}
void Test03()
{
    int m, n;
    int i, j;
    int count = 0;
    float result = 0.0;
    scanf("%d %d", &m, &n);

    //是 一个指针，指向一个数组，数组有n个元素，每个元素类型是int, 数组指针
    int (*p1)[n] = (int (*)[n])malloc(m*n*sizeof(int));
    

    int (*p2)[n] = (int (*)[n])malloc(m*n*sizeof(int));
    if(p2==NULL)
    {
        fprintf(stderr, "Memory Allocction failed!\n");
        exit(EXIT_FAILURE);
    }

    init(m, n, p1);
    init(m, n, p2);
    
    
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(p1[i][j]==p2[i][j])
            {
                count++;
            }
        }
    }
    
    result = 100*(float)(count)/(float)(m*n);
    
    printf("%.2f\n", result);
    
    free(p1);
    free(p2);
    p1 = NULL;
    p2 = NULL;
}

/*
Test04():
    描述
    KiKi现在得到一个包含n*m个数的整数序列，现在他需要把这n*m个数按顺序规划成一个n行m列的矩阵并输出，请你帮他完成这个任务。
    输入描述：
    一行，输入两个整数n和m，用空格分隔，第二行包含n*m个整数（范围-231~231-1）。(1≤n≤10, 1≤m≤10)
    输出描述：
    输出规划后n行m列的矩阵，每个数的后面有一个空格。

    示例1
    输入：
    2 3
    1 2 3 4 5 6
    输出：
    1 2 3
    4 5 6
*/
void print_twodim(int n, int m, int *p2, int p1[n][m])
{
    int i, j;
    
    for(i=0; i<n*m; i++)
    {
        scanf("%d", (p2+i));
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            p1[i][j] = *(p2+j+(m*i));
            printf("%d ", p1[i][j]);
        }
        printf("\n");
    }
}
void Test04()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int (*p1)[] = (int (*)[])malloc(sizeof(int)*n*m);
    if(p1 == NULL)
    {
        fprintf(stderr, "Memory allocction failed!\n");
        exit(EXIT_FAILURE);
    }
    int * p2 = (int *)malloc(sizeof(int)*n*m);
    if(p2 == NULL)
    {
        fprintf(stderr, "Memory allocction failed!\n");
        exit(EXIT_FAILURE);
    }
    print_twodim(n, m, p2, p1);
    
    free(p1);
    free(p2);
    p1 = NULL;
    p2 = NULL;
}

/*
Test05():
    描述
    KiKi知道什么叫杨辉三角之后对杨辉三角产生了浓厚的兴趣，
    他想知道杨辉三角的前n行，请编程帮他解答。杨辉三角，
    本质上是二项式(a+b)的n次方展开后各项的系数排成的三角形。
    其性质包括：每行的端点数为1， 一个数也为1；每个数等于它左上方和上方的两数之和。

    输入描述：
    第一行包含一个整数数n。 (1≤n≤30)
    输出描述：
    包含n行，为杨辉三角的前n行，每个数输出域宽为5。

    输入：
        6
    输出：
        1
        1    1
        1    2    1
        1    3    3    1
        1    4    6    4    1
        1    5   10   10    5    1
*/

void print_arr(int n, int arr[n][n])
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<=i; j++)
        {
            if(j==0 || j==i)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            printf("%5d", arr[i][j]);   
        }
        printf("\n");
    }
}

void Test05()
{
    int n;
    scanf("%d", &n);
    int (*p)[] = (int (*)[])malloc(n*n*sizeof(int));
    if(p==NULL)
    {
        fprintf(stderr, "Memory Alloction Failed!\n");
        exit(EXIT_FAILURE);
    }
    
    print_arr(n, p);
    
    free(p);
    p = NULL;
}

/*
Test06():
    描述
    KiKi和BoBo玩 “井”字棋。也就是在九宫格中，
    只要任意行、列，或者任意对角线上面出现三个连续相同的棋子，就能获胜。请根据棋盘状态，判断当前输赢。

    输入描述：
    三行三列的字符元素，代表棋盘状态，字符元素用空格分开，
    代表当前棋盘，其中元素为K代表KiKi玩家的棋子，
    为O表示没有棋子，为B代表BoBo玩家的棋子。

    输出描述：
    如果KiKi获胜，输出“KiKi wins!”；
    如果BoBo获胜，输出“BoBo wins!”；
    如果没有获胜，输出“No winner!”。

    示例1
        输入：
        K O B
        O K B
        B O K
        输出：
        KiKi wins!
*/

void Test06()
{
    char chess[3][3];
    char tag = '0';
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%c", &chess[i][j]);
            getchar();//吸收换行
        }
    }

    for(i=0; i<3; i++)
    {
        //判断每一行
        if(chess[i][0] == chess[i][1] && chess[i][1] == chess[i][2])
            tag = chess[i][0];
        //判断每一列
        else if(chess[0][i] == chess[1][i] && chess[i][1] == chess[2][i])
            tag = chess[0][i];
    }

    //判断对角线
    if(chess[0][0] == chess[1][1] && chess[1][1] == chess[2][2])
    {
        tag = chess[0][0];
    }
    else if(chess[0][2] == chess[1][1] &&  chess[1][1] == chess[2][0])
    {
        tag = chess[0][2];
    }

    if(tag == 'K')
        printf("KiKi wins!\n");
    else if(tag == 'B')
        printf("BoBo wins!\n");
    else 
        printf("No winner!\n");
}

/*
Test07():
    描述
小sun上课的时候非常喜欢玩扫雷。他现小sun有一个初始的雷矩阵，他希望你帮他生成一个扫雷矩阵。
扫雷矩阵的每一行每一列都是一个数字，每个数字的含义是与当前位置相邻的8个方向中，有多少个雷（在下图中，雷用*表示）；
如果当前位置就是雷的话，仍输出一个*。

    比如初始的雷矩阵如下：
    ....
    ..**
    *.*.
    .*.*
    对应的数字矩阵为：
    0122
    13**
    *4*4
    2*3* 

    输入描述：
    第一行两个整数n,m，代表矩阵有n行m列

    接下来共n行，每行m个字符

    输出描述：
    输出共n行m列，为扫雷矩阵。
*/
void init_arrays(int n, int m, char arr[n+2][m+2])
{
    int i, j;
    for(i=1; i<n+1; i++)
    {
        for(j=1; j<m+1; j++)
        {
            scanf("%c", &arr[i][j]);
        }
        getchar();//吸收换行字符
    }
}

void print_arrays(int n, int m, char arr[n+2][m+2])
{
    int i, j;
    int count;
    int si, sj;
    for(i=1; i<n+1; i++)
    {
        for(j=1; j<m+1; j++)
        {
            if(arr[i][j]=='*')
            {
               printf("*");
            }
            else
            {
                count = 0;
                for(si = i-1; si<=i+1; si++)
                {
                    for(sj = j-1; sj<=j+1; sj++)
                    {
                        if(arr[si][sj] == '*')
                            count++;
                    }
                }
                printf("%d", count);
            }
        }
        printf("\n");
    }
}
void Test07()
{
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    char (*p)[] = (char (*)[])malloc((n+2)*(m+2)*sizeof(char));
    if(p == NULL)
    {
        fprintf(stderr, "Memory Allocation Failed!\n");
        exit(EXIT_FAILURE);
    }
    init_arrays(n, m, p);
    print_arrays(n, m, p);
    
    free(p);
    p= NULL;
}
int main(void)
{
    //Test01();
    //Test02();
    //Test03();
    //Test04();
    //Test05();
    //Test06();
    Test07();
}

