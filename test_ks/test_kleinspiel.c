#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
    printf("*******************************************\n");
    printf("*****   1.Play  **********  0.Exit   ******\n");
    printf("*******************************************\n");
}
void game()
{
    //1.generiern Random Zahl
    int rad = 1;
    int guess = 0;
    rad = rand()%100+1; //生成随机数0～100， (0~99)+1
    //printf("%d\n", rad);
    //2. Erraten die Zahl 猜数字
    while (1)
    {
        printf("Bitte erraten eine Zahl:>");
        scanf("%d", &guess);
        if(guess>rad)
        {
            printf("Ein bisschen größer..\n");
        }
        else if (guess<rad)
        {
            printf("Ein bisschen kleiner..\n");
        }
        else
        {
            printf("Bingo Richtig!\n");
            break;
        }
        
    }
    
}
int main()
{
    int input = 1;
    //time random zahl （Unix）
    //时间戳（Unix）： 当前时间-计算机起始时间（1970,1,1,0:0:00) = (xxxx)s
    //time_t time(time_t *timer) //time函数，返回类型time_t, 参数类型*timer
    srand((unsigned int)time(NULL));//NULL 空指针，srand（）设置随机数生成起点
    do
    {
        menu();
        printf("Bitte geben Sie ein Value ein:>");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("Game Exit!\n");
                break;
            default:
                printf("Eingeben Fehler!\n");
                break;
        }
    } while (input);
    return 0;
}