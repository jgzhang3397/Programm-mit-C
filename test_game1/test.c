//testen ein Spiel 三子棋
#include<time.h>
//#include<stdio.h>
#include<stdlib.h>
#include"game.h"//inhalt stdio.h
#include"game.c"
//die Realisierung des ganz Games
void game()
{
    char ret = 0;
    //arrays um die Informationen des Boards zu spreichern
    char board[ROW][COL]={0};//alles muss ' ' sein
    //board initialisieren
    InitBoard(board, ROW, COL);
    //Display Board zeigen
    DisplayBoard(board, ROW, COL);
    //Schach spielen
    while (1)
    {
        //Player spielen
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //feststellen, ob player gewonnen
        ret = IsWin(board, ROW, COL);
        if(ret != 'c')
        {
            break;
        }
        //Host spielen
        HostMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //feststellen, ob host gewonnen
        ret = IsWin(board, ROW, COL);
        if(ret != 'c')
        {
            break;
        }
    }
    if(ret == '*')
    {
        printf("Du bist gewonnen!! :)\n");
    }
    else if (ret == '#')
    {
        printf("Du bist verloren?? :(\n");
    }
    else
    {
        printf("Niemand gewonnen === gleich Nievau\n");
    }    
}
void menu()
{
    printf("\n**************************************\n");
    printf("*******1.Spielen     0.Exit***********\n");
    printf("**************************************\n");
    
}
void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("Bitte geben Sie eine Value ein:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            //printf("Fangen wir an!\n");
            game();
            break;
        case 0:
            printf("Exit the game!!\n");
            break;
        default:
            printf("Bitte noch einmal waehlen?\n");
            break;
        }
    } while (input);
    
}
int main()
{
    test();
    return 0;
}