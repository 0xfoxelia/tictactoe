#include <stdio.h>
#include <stdlib.h>

#include "tictactoe.h"

void printBoard(int board[][SIZE])
{
    char element;

    for(int i = 0; i < SIZE; i++)
    {
        for(int y = 0; y < SIZE; y++)
        {
            if(board[i][y] == 0)
            {
                element = ' ';
            }
            else if(board[i][y] == 1)
            {
                element = 'X';
            }
            else
            {
                element = 'O';
            }

	    printf("%c ", element);

            if(y < SIZE - 1)
            {
		printf("| ");
            }

        }
	putchar('\n');
        if(i < SIZE - 1)
        {
	    printf("- - - - -\n");
        }
    }
}

void clearInputBuffer()
{    
    int garbage;
    while((garbage = getchar()) != '\n' && garbage != EOF);
}

bool checkCordinates(int row, int col, int board[][SIZE])
{
    if((row < 0 && row > 2) || (col < 0 && col > 2)) return false;

    if(board[row][col] != 0) return false;

    return true;
}

void updateBoard(int row, int col, int board[][SIZE])
{
    board[row][col] = 1;
}
