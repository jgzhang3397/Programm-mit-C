
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"game.h"
#include"game.c"

void game()
{
    //die Informationen der Mine speichern
    //1.Layout draußen
    char mine[ROWS][COLS]={0};
    //2.Layout innern
    char show[ROWS][COLS]={0};
    //Initilaiseren
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    //Print Board
        //DisplayBoard(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);
    //Mine aufbauen
    SetMine(mine, ROW, COL);
    DisplayBoard(mine, ROW, COL);
    //Mine suchen
    FindMine(mine, show, ROW, COL);

}
void menu()
{
    printf("\n####################################\n");
    printf("#######     1. Spielen    ##########\n");
    printf("#######     0. Exit       ##########\n");
    printf("####################################\n");
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
            game();//Inhalt des Spieles
            break;
        case 0:
            printf("Exit the game!!\n");
            break;
        default:
            printf("Geben Sie eine wirksame Value ein bitte:>\n");
            break;
        }
    }while(input);
}
int main()
{
    test();
    return 0;
}