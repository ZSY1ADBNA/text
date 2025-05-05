#include"mines.h"
int main() {
    char board[ROWS][COLS];
    char visible[ROWS][COLS];
    initializeBoard(board, visible);
    placeMines(board);

    int row, col;
    bool gameOver = false;
    while (!gameOver) {
        printBoard(visible);
        printf("请输入要翻开的格子的行和列 (用空格分隔): ");
        scanf_s("%d %d", &row, &col);
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            printf("输入无效，请重新输入。\n");
            continue;
        }
        if (!revealCell(board, visible, row, col)) {
            gameOver = true;
            printf("你踩到地雷了，游戏结束！\n");
        }
        else if (checkWin(visible)) {
            gameOver = true;
            printf("恭喜你，你赢了！\n");
        }
    }
    // 游戏结束后显示完整棋盘
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visible[i][j] = board[i][j];
        }
    }
    printBoard(visible);
    return 0;
}