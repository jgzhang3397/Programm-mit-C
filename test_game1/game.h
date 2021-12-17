#include<stdio.h>
#define ROW 3
#define COL 3

//Erklaerung
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void HostMove(char board[ROW][COL], int row, int col);

//=======4 mal Situtationen
//1. Player gewonnen -- '*'
//2. Host gewonnen  -- '#'
//3. nimand gewonnen -- 'o'
//4. weiter spielen  -- 'c'
char IsWin(char board[ROW][COL], int row, int col);