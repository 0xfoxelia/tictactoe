#include <stdio.h>
#include <stdlib.h>

#include "tictactoe.h"

int main(void){

    int board[][SIZE] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    //printBoard(board);

    printf("Type the row you want to select: ");
    int row = getchar() - '0' - 1;
    clearInputBuffer();
    
    printf("Type the column you want to select: ");
    int col = getchar() - '0' - 1;
    clearInputBuffer();

    if(checkCordinates(row, col, board)) updateBoard(row, col, board);
    printBoard(board);
    
    return 0;

}
