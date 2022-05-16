#include <stdio.h>
#include <string.h>
#include <math.h>

int htoi(char input[], int len);

// 编写函数htoi(s), 把十六进制的字符串转换成等价的整数值
int main()
{
    char input[100] = {0};
    scanf("%s", input);
    int len =  strlen(input);
    int result = htoi(input, len);

    printf("%d\n", result);
    return 0;
}

int htoi(char input[], int len)
{
    int i = 0;
    int sum = 0;
    int temp;
    int j = 0;
    if(input[0]== '0' && (input[1] == 'x' || input[1] == 'X'))
        input[1] = '0';
    for(i=len-1; i>=0; i--)
    {
        temp = 0;
        if(input[i]>= '0' && input[i]<='9')
            temp = (int)pow(16, j)* (int)(input[i] - '0');
        else if(input[i]>= 'a' && input[i]<= 'f')
            temp = (int)pow(16, j)* ((int)input[i] - 97 + 10);
        else if(input[i]>= 'A' && input[i]<= 'F')
            temp = (int)pow(16, j)* ((int)input[i] - 65 + 10);
        else 
            return -1;
        sum += temp;
        j++;
    }
    return sum;
}