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
            else if(board[i][y] == 2)
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

bool checkCoordinates(int row, int col, int board[][SIZE])
{
    if((row < 0 || row > 2) || (col < 0 || col > 2))
    {
        printf("Invalid Coordinates.\n");
        return false;
    }

    else if(board[row][col] != 0)
    {
        printf("That point is already used.\n");
        return false;
    }

    return true;
}

void updateBoard(int row, int col, int board[][SIZE])
{
    board[row][col] = 1;
}

void clearScreen()
{
    printf("\033[2J\033[H");
}

bool checkWin(int board[][SIZE], int player)
{
    //rows
    if(board[0][0] == player && board[0][1] == player && board[0][2] == player) return true;
    else if(board[1][0] == player && board[1][1] == player && board[1][2] == player) return true;
    else if(board[2][0] == player && board[2][1] == player && board[2][2] == player) return true;

    //colums
    else if(board[0][0] == player && board[1][0] == player && board[2][0] == player) return true;
    else if(board[0][1] == player && board[1][1] == player && board[2][1] == player) return true;
    else if(board[0][2] == player && board[1][2] == player && board[2][2] == player) return true;

    //middles

    else if(board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    else if(board[0][2] == player && board[1][1] == player && board[0][0] == player) return true;
    else return false;
    
    
}
