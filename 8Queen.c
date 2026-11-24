
#include <stdio.h>
#define N 8

int board[N][N] = {0};

int isSafe(int row, int col) {
    int i, j;

    for(i=0; i<col; i++)
        if(board[row][i])
            return 0;

    for(i=row,j=col; i>=0 && j>=0; i--,j--)
        if(board[i][j])
            return 0;

    for(i=row,j=col; i<N && j>=0; i++,j--)
        if(board[i][j])
            return 0;

    return 1;
}

int solveQueens(int col) {
    if(col>=N)
        return 1;

    for(int row=0; row<N; row++) {
        if(isSafe(row,col)) {
            board[row][col]=1;

            if(solveQueens(col+1))
                return 1;

            board[row][col]=0;
        }
    }
    return 0;
}

int main() {
    if(solveQueens(0)) {
        printf("Solution for 8 Queens Problem:\n\n");

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(board[i][j])
                    printf(" Q ");
                else
                    printf(" . ");
            }
            printf("\n");
        }
    }
    else {
        printf("No solution exists.");
    }

    return 0;
}
