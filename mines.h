#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10
#define MINES 10
void initializeBoard(char board[ROWS][COLS], char visible[ROWS][COLS]);//初始化
void placeMines(char board[ROWS][COLS]);//放雷
void printBoard(char visible[ROWS][COLS]);//打印棋盘
bool revealCell(char board[ROWS][COLS], char visible[ROWS][COLS], int row, int col);//翻格子
bool checkWin(char visible[ROWS][COLS]);
