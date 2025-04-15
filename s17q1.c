#include <stdio.h>
#include <stdbool.h>
#define N 8
int board[N][N];

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool solveNQueensUtil(int col) {
    if (col >= N) {
        return true;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            if (solveNQueensUtil(col + 1)) {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

bool solveNQueens() {
    if (!solveNQueensUtil(0)) {
        printf("Solution does not exist.\n");
        return false;
    }
    printf("Solution for N-Queens problem:\n");
    printSolution();
    return true;
}

int main() {
    if (N <= 3) {
        printf("No solution exists for N less than or equal to 3.\n");
        return 1;
    }
    solveNQueens();
    return 0;
}
