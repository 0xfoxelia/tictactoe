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

    printf("Welcome in tictactoe game:\n\n");
    
    while(true)
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
            clearScreen();
            printBoard(board);
            clearScreen();
        }
        else
        {
            printf("%s", coordinates.msg);
            thrd_sleep(&(struct timespec){.tv_sec=5}, NULL);
            clearScreen();
            continue;
        }

        if(fullBoard(board))
        {
            if(checkWin(board, player))
            {
                printf("You win.\n");
                break;
            }
            else if(checkWin(board, cpu))
            {
                printf("You lose.\n");
                break;
            }
            else {
                printf("No one is the winner.\n");
                break;
            }
        }

        if(checkWin(board, player))
        {
            printf("You win.\n");
            break;
        }
        
        cpuChoice(board, cpu);
        
        if(checkWin(board, cpu))
        {
            printf("You lose.\n");
            break;
        }
    }

    putchar('\n');
    printBoard(board);
    putchar('\n');
    
    return 0;
}
