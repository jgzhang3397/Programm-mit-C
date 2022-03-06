#include<stdio.h>
#include<math.h>

/*
Test01():
    计算一元二次方程

    描述
    从键盘输入a, b, c的值，编程计算并输出一元二次方程ax2 + bx + c = 0的根，
    当a = 0时，输出“Not quadratic equation”，当a ≠ 0时，根据△ = b2 - 4*a*c的三种情况计算并输出方程的根。

    输入描述：
    多组输入，一行，包含三个浮点数a, b, c，以一个空格分隔，表示一元二次方程ax2 + bx + c = 0的系数。

    输出描述：
    针对每组输入，输出一行，输出一元二次方程ax2 + bx +c = 0的根的情况。

    如果a = 0，输出“Not quadratic equation”；

    如果a ≠  0，分三种情况：

        △ = 0，则两个实根相等，输出形式为：x1=x2=...。

        △  > 0，则两个实根不等，输出形式为：x1=...;x2=...，其中x1  <=  x2。

        △  < 0，则有两个虚根，则输出：x1=实部-虚部i;x2=实部+虚部i，
        即x1的虚部系数小于等于x2的虚部系数，实部为0时不可省略。实部= -b / (2*a),虚部= sqrt(-△ ) / (2*a)

    
    所有实数部分要求精确到小数点后2位，数字、符号之间没有空格。

    注意示例：
        输入：4 0 0
        输出：x1=x2=0.00
        需要求根公式 + 0， 因为 -0 + 0 = 0
*/

void Test01()
{
    float a, b, c;
    float dolta;
    float x1, x2;
    float real_p, imag_p;
    while(scanf("%f %f %f", &a, &b, &c)!=EOF)
    {
        dolta = pow(b,2) - 4*a*c;
        x1 = (-b - sqrt(dolta))/(2*a) + 0;
        x2 = (-b + sqrt(dolta))/(2*a) + 0;
        real_p = -b/(2*a);
        imag_p = sqrt(-dolta)/(2*a);
        
        if(a!=0)
        {
            if(dolta == 0)
                printf("x1=x2=%.2f\n", x2);
            else if(dolta > 0)
                printf("x1=%.2f;x2=%.2f\n", x1, x2);
            else 
                printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi",real_p,
                      imag_p, real_p, imag_p);
        }
        else
            printf("Not quadratic equation\n");
    }
}

/*
Test02()[没写完]&Test03():
    描述
    每一本正式出版的图书都有一个ISBN号码与之对应，ISBN码包括9位数字、1位识别码和3位分隔符，其规定格式如“x-xxx-xxxxx-x”，
    其中符号“-”是分隔符（键盘上的减号），最后一位是识别码，例如0-670-82162-4就是一个标准的ISBN码。
    ISBN码的首位数字表示书籍的出版语言，例如0代表英语；第一个分隔符“-”之后的三位数字代表出版社，
    例如670代表维京出版社；第二个分隔之后的五位数字代表该书在出版社的编号；最后一位为识别码。

    识别码的计算方法如下：
    首位数字乘以1加上次位数字乘以2……以此类推，用所得的结果mod 11，
    所得的余数即为识别码，如果余数为10，则识别码为大写字母X。
    例如ISBN号码0-670-82162-4中的识别码4是这样得到的：对067082162这9个数字，从左至右，分别乘以1，2，…，9，再求和，
    即0×1+6×2+……+2×9=158，然后取158 mod 11的结果4作为识别码。
    
    你的任务是编写程序判断输入的ISBN号码中识别码是否正确，
    如果正确，则仅输出“Right”；
    如果错误，则输出你认为是正确的ISBN号码。

    输入描述：
    只有一行，是一个字符序列，表示一本书的ISBN号码（保证输入符合ISBN号码的格式要求）。

    输出描述：
    共一行，假如输入的ISBN号码的识别码正确，那么输出“Right”，否则，按照规定的格式，输出正确的ISBN号码（包括分隔符“-”）。

    示例1
    输入：
        0-670-82162-4
    输出：
        Right

*/
void Test02()
{
    char buf_char[13];
    int buf_int[10];
    int sum = 0;
    int n = 0;
    /*将原来的数组：0-670-82162-4
        改变成：0670821624---  
    */
    for(int i = 0; i<13; i++)
    {
        scanf("%c",&buf_char[i]);
        char temp = '0';
        while (i<10)
        {
            if(buf_char[i] == '-')
            {
                temp = buf_char[i];
                buf_char[i] = buf_char[i+1];
                buf_char[i+1] = temp;
                i--;
            }
        }  
    }  

    //将改变后的字符数组的前10个元素转换成数字类型，得到数字类型数组
    for (int i = 0; i < 10; i++)
    {
        buf_int[i] = buf_char[i]-'0';

        //根据求和公式，得到前9个元素的和
        while (i<9)
        {
            sum = buf_int[i]*(i+1);
        }   
        
    }

    n = sum % 11; //得到识别码

    if(n==10)
    {
        if(buf_char[12]=='X')
            printf("Right\n");
        else
        {
            buf_char[12]='X';
            for (int i = 0; i < 13; i++)
            {
                printf("%c",buf_char[i]);
            }
            
        }
    }
    else if(n==buf_char[12])
        printf("Right\n");
    else
    {
        for (int i = 0; i < 13; i++)
            {
                printf("%c",buf_char[i]);
            }
    }   
}
void Test03()
{
    char buf[13]="";
    int a=0;
    for(int i=0;i<13;i++){
        scanf("%c",&buf[i]);
    }
    a = ((buf[0]-'0')*1+
            (buf[2]-'0')*2+
            (buf[3]-'0')*3+
            (buf[4]-'0')*4+
            (buf[6]-'0')*5+
            (buf[7]-'0')*6+
            (buf[8]-'0')*7+
            (buf[9]-'0')*8
            +(buf[10]-'0')*9) % 11;
     
    if(a==10){
        if(buf[12]=='X'){
            printf("Right");
        }else{
            buf[12]='X';
            printf("%s",buf);
        }
    }else{
        if(a==(buf[12]-'0')){
            printf("Right");
        }else{
            buf[12]=a%10+'0';
            printf("%s",buf);
        }
    }
}

/*
Test04():
    描述
    KiKi知道了什么是质数（只能被1和他自身整除的数），他现在想知道所有三位整数中，有多少个质数。

    输入描述：
    无

    输出描述：
    一行，一个整数，表示所有三位整数中，有多少个质数。
*/

void Test04()
{
    int count = 0;
    int is_prime;
    for(int i = 100; i<=999; i++)
    {
        is_prime = 1;
        for(int j = 2; j<=sqrt(i); j++)
        {
            if(i%j==0)
            {
                is_prime = 0;
                break;
            }     
        }
        if(is_prime == 1)
            count ++;
    }
    printf("%d\n",count);
}

/*
Test05():
    描述
        牛牛准备继续进阶，计算更难的数列
        输入一个整数n,计算 1+1/（1-3）+1/（1-3+5）+...+1/(1-3+5-...((-1)^(n-1))*(2n-1))的值

    输入描述：
        输入一个整数
    输出描述：
        输出一个浮点数，保留3位小数

        输入：
            1
        输出：
            1.000
*/
void Test05()
{
    int n;
    double sum = 0.0;

    int deno = 0;;
    double deno_f;

    scanf("%d", &n);
    
    for(int i = 1; i<=n; i++)
    {    
        deno = 0;//分母每次要init为0

        for(int j = 1; j<=i; j++)
        {
            deno += pow(-1, j-1)*(2*j-1);
        }
        
        deno_f = (double)deno;
        sum += 1.0/deno_f;
    }
    
    printf("%.3lf\n", sum);
}

/*
Test06():
    描述
    今年是2019年，KiKi想知道1~2019中有多少个包含数字9的数。包含数字的数是指有某一位是“9”的数，例如“2019”、“199”等。

    输入描述：
            无
    输出描述：
            一行，一个整数，表示1~2019中共有多少个数包含数字9。
*/
void Test06()
{
    int count = 0;
    for(int i = 1; i<=2019; i++)
    {
        int t = i;//保证i不受后面代码影响
        while(t)
        {
            if(t % 10 == 9)
            {
                count++;
                break;//退出while循环
            }
            
            t /= 10;
        }
    }
    printf("%d\n", count);
}

/*
Test07():
    描述
    春天是鲜花的季节，水仙花就是其中最迷人的代表，数学上有个水仙花数，
    他是这样定义的： “水仙花数”是指一个三位数，它的各位数字的立方和等于其本身，
    比如：153=1^3+5^3+3^3。 现在要求输出所有在m和n范围内的水仙花数。

    输入描述：
    输入数据有多组，每组占一行，包括两个整数m和n（100 ≤ m ≤ n ≤ 999）。

    输出描述：
    对于每个测试实例，要求输出所有在给定范围内的水仙花数，
    就是说，输出的水仙花数必须大于等于m,并且小于等于n，
    如果有多个，则要求从小到大排列在一行内输出，之间用一个空格隔开; 
    如果给定的范围内不存在水仙花数，则输出no; 每个测试实例的输出占一行。

    示例1
        输入：
            100 120
            300 380
        输出：
            no
            370 371
*/

int get_Num(int x)
{
    int sum = 0;
    int t = x;
    while(t)
    {
        sum += pow(t%10,3);
        t /= 10;
    }
    if(sum == x)
        return 1;
    else
        return 0;  
}

void Test07()
{
    int m, n;
    int flag = 0;
    while(scanf("%d %d", &m, &n)!=EOF)
    {
        for(int i = m; i<=n; i++)
        {
            while (get_Num(i))
            {
                flag = 1;//如果出现了水仙花数就不能打印no
                printf("%d ", i);
                break;
            }

            if(i==n && flag == 0)
                printf("no\n");     
        }
    }
}

/*
Test08():
    描述
    变种水仙花数 - Lily Number：把任意的数字，从中间拆分成两个数字，
    比如1461 可以拆分成（1和461）,（14和61）,（146和1),如果所有拆分后的乘积之和等于自身，
    则是一个Lily Number。

    例如：

    655 = 6 * 55 + 65 * 5

    1461 = 1*461 + 14*61 + 146*1

    求出 5位数中的所有 Lily Number。

    输入描述：
    无
    输出描述：
    一行，5位数中的所有 Lily Number，每两个数之间间隔一个空格。

    double pow (double base, double exponent);
*/

int get_LilyNumber(int x, int n)
{
    int sum = 0;
    for(int i = 1; i<=n; i++)
    {
        sum += (x%(int)(pow(10,i)))*(x/(int)(pow(10,i)));
    }
    if(sum == x)
        return 1;
    else
        return 0;
}

void Test08()
{
    for(int i = 10000; i<=99999; i++)
    {
        if(1==get_LilyNumber(i,5))
            printf("%d ", i);
    }
    printf("\n");
}

/*
Test08():
    描述
    公务员面试现场打分。有7位考官，从键盘输入若干组成绩，每组7个分数（百分制），去掉一个最高分和一个最低分，输出每组的平均成绩。
    （注：本题有多组输入）

    输入描述：
    每一行，输入7个整数（0~100），代表7个成绩，用空格分隔。
    输出描述：
    每一行，输出去掉最高分和最低分的平均成绩，小数点后保留2位，每行输出后换行。
*/
double get_Avg(int n)
{
    int x;
    int min = 100;
    int max = 0;
    int sum = 0;
    double result = 0.0;
    
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&x);//注意scanf后不加空格不然最后一位数读不出
        if(min>x)
            min = x;
        if(max<x)
            max = x;

        sum += x;
    }

    result = (double)(sum - (min+max))/(n-2);
    
    return result;

}

void Test09()
{
    double result = 0.0;
    do
    {
        result = get_Avg(7);
        printf("%.2lf\n", result);
    }while (1);
}
int main()
{
    //Test01();
    //Test02();
    //Test03();
    //Test04();
    //Test05();
    //Test06();
    //Test07();
    //Test08();
    Test09();
    return 0;
}

