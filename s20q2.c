#include <stdio.h>
#include <stdbool.h>

#define N 4

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int board[N][N], int i, int j) {
    for (int k = 0; k < j; k++) {
        if (board[i][k]) {
            return false;
        }
    }

    for (int x = i, y = j; x >= 0 && y >= 0; x--, y--) {
        if (board[x][y]) {
            return false;
        }
    }

    for (int x = i, y = j; x < N && y >= 0; x++, y--) {
        if (board[x][y]) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(int board[N][N], int col) {
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQueensUtil(board, col + 1)) {
                return true;
            }
            board[i][col] = 0;
        }
    }

    return false;
}

bool solveNQueens() {
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0)) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    solveNQueens();
    return 0;
}
