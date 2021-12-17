#include<math.h>
#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for(i=0; i<row; i++)
    {
        // //print eine Zeile
        // printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        // //print Zeile zu trennen
        // if(i<row-1)
        //     printf("---|---|---\n");
        //==============Optimerung=====================
        int j = 0;
        for(j=0; j<col; j++)
        {
            //Print eine Zeile
            printf(" %c ", board[i][j]);
            if(j<col-1)
            {
                printf("|");
            }
        }
        printf("\n");
        //Print Zeile zu trennen
        if(i<row-1)
        {
            for(j=0; j<col ; j++)
            {
                printf("---");
                if(j<col-1)
                {
                    printf("|");
                }
            }
            printf("\n");
        }

    }
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("Du bist daran!\n");
    while (1)
    {
        printf("Bitte geben Sie die Koordinate:>[Form = (x y)]");
        scanf("%d%d", &x, &y);
        //feststellen, ob die Koordinate noch verfuegbar ist
        if(x>=1 && x<= row || y>=1 && y<= col)
        {
            if(board[x-1][y-1]==' ')
            {
                board[x-1][y-1]='*';
                break;
            }
            else
            {
                printf("Die Koordinate nicht mehr zu haben..\n");
            }
        }
        else
        {
            printf("Es geht nicht, bitte geben nochmal ein:>\n");
        }
    }
    
}
void HostMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("Host ist daran:>\n");
    while (1)
    {
        x = rand() % row;
        y = rand() % col;
        if(board[x][y]==' ')
        {
            board[x][y]='#';
            break;
        }
    }
}
//1 bedeutet Full, 0 bedeutet nicht full
int isFull(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for ( i = 0; i < row; i++)
    {
        for( j = 0; j < col; j++)
        {
            if(board[i][j]== ' ')
            {
                return 0;// nicht voll
            }
        }
        
    }
    return 1; //voll
}
char IsWin(char board[ROW][COL], int row, int col)
{
    int i = 0;
    //3 mal Zeile feststellen
    for ( i = 0; i < row; i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' ')
        {
            return board[i][1];
        }
    }
    //3 mal Spalte feststellen
    for(i = 0; i< col; i++)
    {
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' ')
        {
            return board[1][i];
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ')
    {
        return board[1][1];
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]!=' ')
    {
        return board[1][1];
    }
    //Feststellen, ob beide gleich Neivau
    if(1==isFull(board, ROW, COL))
    {
        return'o';
    }
    else
    {
        return'c';
    }
    
}