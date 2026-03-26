#include<stdio.h>

#define MAX 10   // maximum size

int board[MAX][MAX];
int N;

// Print solution
void printBoard() {
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Check safe position
int isSafe(int row, int col){
    int i, j;

    // Check column
    for(i = 0; i < row; i++){
        if(board[i][col] == 1)
            return 0;
    }

    // Check left diagonal
    for(i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 1)
            return 0;
    }

    // Check right diagonal
    for(i = row-1, j = col+1; i >= 0 && j < N; i--, j++){
        if(board[i][j] == 1)
            return 0;
    }

    return 1;
}

// Backtracking
int solve(int row){
    int col;

    if(row == N){
        printBoard();
        return 1;
    }

    for(col = 0; col < N; col++){
        if(isSafe(row, col)){
            board[row][col] = 1;

            solve(row + 1);

            board[row][col] = 0;  // backtrack
        }
    }

    return 0;
}

// Main
int main(){
    int i, j;

    printf("Enter number of queens: ");
    scanf("%d", &N);

    // Initialize board
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            board[i][j] = 0;
        }
    }

    solve(0);

    return 0;
    
}
