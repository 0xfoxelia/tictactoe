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


    struct errHandling coordinates;

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

        checkCoordinates(row, col, board, &coordinates);
        if(coordinates.value)
        {    
            updateBoard(row, col, board, player);
            cpuChoice(board, cpu);
            clearScreen();
        }
        else
        {
            printf("%s", coordinates.msg);
            thrd_sleep(&(struct timespec){.tv_sec=10}, NULL);
            clearScreen();
            continue;
        }
        
        
        bool winPlayer = checkWin(board, player);
        if(winPlayer)
        {
            printf("You win");
            break;
        }
        
        
    
    }
    while(true);
    
    return 0;

}
