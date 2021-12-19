//#include<math.h>
#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
        
    } 
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    //print die Nummer von Spalte
    for (i = 0; i <=col; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for ( i = 1; i <=row; i++)
    {
        printf("%d ", i);//die Nummer der Zeile
        for (j = 1; j <=col; j++)
        {
            printf("%c ", board[i][j]);     
        }
        printf("\n"); 
    }
     printf("==========================================\n");
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = rand()%row+1;//1-9
        int y = rand()%col+1;
        if(board[x][y]=='0')
        {
            board[x][y]='1';
            count--;
        }
    }
    
}
void Boom(char show[ROWS][COLS], int x, int y)
{
    int i = 0;
    int j = 0;
    for (i = -1; i <=1; i++)
    {
        for(j = -1; j<=1; j++)
        {
            show[x+i][y+j]=' ';
            //Boom(show[x+i][y+j], x, y);
        }
    }
}
//'0' - '0' = 0;
//'1' - '0' = 1;
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    return  mine[x-1][y-1]+
            mine[x-1][y]+
            mine[x-1][y+1]+
            mine[x][y-1]+
            mine[x][y+1]+
            mine[x+1][y-1]+
            mine[x+1][y]+
            mine[x+1][y+1] - 8*'0';
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x, y=0;
    int win = 0;
    while (win<row*col-EASY_COUNT)
    {   
        printf("Bitte geben Sie die Koordinate x und y ein:>");
        scanf("%d%d", &x, &y);
        if(x>=1 && x<=row && y>=1 && y<=col)
        {
            //richtige Koordinate
            if(mine[x][y]=='1')
            {
                printf("Schade, du bist tot!\n");
                DisplayBoard(mine, row, col);
                break;
            }
            else//not Mine
            {
                //muss rechnen, wie viel Mines in der Naehe
                int count = get_mine_count(mine, x, y );
                if(count == 0)
                {
                    Boom(show, x, y);
                    DisplayBoard(show, row, col);
                    //FindMine(mine, show, row, col);
                }
                else
                {
                    show[x][y] = count +'0';
                    DisplayBoard(show, row, col);
                    win++;
                }
            }
        }
        else
        {
            printf("Falsche Kooradinate: Versuch nochmal!\n");
        }
    }
    if(win==row*col-EASY_COUNT)
    {
        printf("U win!!, Herzlichen Glueckwunsch:)\n");
        DisplayBoard(mine, row, col);
    }
}