#include"mines.h"
// 初始化棋盘
void initializeBoard(char board[ROWS][COLS], char visible[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '0';
            visible[i][j] = '-';
        }
    }
}

// 布置地雷
void placeMines(char board[ROWS][COLS]) {
    srand((unsigned)time(NULL));
    int minesPlaced = 0;
    while (minesPlaced < MINES) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (board[row][col] != '*') {
            board[row][col] = '*';
            minesPlaced++;
            // 更新周围格子的数字
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) continue;
                    int newRow = row + i;
                    int newCol = col + j;
                    if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && board[newRow][newCol] != '*') {
                        board[newRow][newCol]++;
                    }
                }
            }
        }
    }
}

// 打印可见棋盘
void printBoard(char visible[ROWS][COLS]) {
    printf("  ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", visible[i][j]);
        }
        printf("\n");
    }
}

// 翻开格子
bool revealCell(char board[ROWS][COLS], char visible[ROWS][COLS], int row, int col) {
    if (board[row][col] == '*') {
        return false;
    }
    if (visible[row][col] != '-') {
        return true;
    }
    visible[row][col] = board[row][col];
    //递归展开空白
    if (board[row][col] == '0') {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int newRow = row + i;
                int newCol = col + j;
                if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS) {
                    revealCell(board, visible, newRow, newCol);
                }
            }
        }
    }
    return true;
}

// 检查是否获胜
bool checkWin(char visible[ROWS][COLS]) {
    int coveredCells = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (visible[i][j] == '-') {
                coveredCells++;
            }
        }
    }
    return coveredCells == MINES;
}