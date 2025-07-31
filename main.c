#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <time.h>

#include "tictactoe.h"

int main(void){

    int board[][SIZE] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    int player = 1;
    int cpu = 2;

    printf("Welcome in tictactoe game\n\n");
    
    do
    {
        printBoard(board);
        printf("\n\n");

        printf("Type the row you want to select: ");
        int row = getchar() - '0' - 1;
        clearInputBuffer();

        printf("Type the column you want to select: ");
        int col = getchar() - '0' - 1;
        clearInputBuffer();

        if(checkCoordinates(row, col, board))
        {
            thrd_sleep(&(struct timespec){.tv_sec=60}, NULL);
            clearScreen();
            updateBoard(row, col, board);
            //printBoard(board);
        }
        else
        {
            
            continue;
        }
        

        bool win = checkWin(board, player);
        if(win)
        {
            printf("You win");
            break;
        }
        
        
    
    }
    while(true);
    
    return 0;

}
