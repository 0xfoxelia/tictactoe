#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void checkCoordinates(int row, int col, int board[][SIZE], struct errHandling *coordinates)
{

    if((row < 0 || row > 2) || (col < 0 || col > 2))
    {
        coordinates->value = false;
        coordinates->msg = "Invalid Coordinates.\n\0";
        return;
    }

    else if(board[row][col] != 0)
    {    
        coordinates->value = false;
        coordinates->msg = "Invalid Coordinates.\n\0"; 
        return;
    }

    coordinates->value = true;
    return;
}

void updateBoard(int row, int col, int board[][SIZE], int activePlayer)
{
    board[row][col] = activePlayer;
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
    else if(board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    else return false;
}

void cpuChoice(int board[][SIZE], int cpu)
{    
    int row;
    int col;
    
    do
    {
    srand(time(0));
    row = rand() % (3 - 1 + 1) + 1 - 1;
    col = rand() % (3 - 1 + 1) + 1 - 1;
    //printf("row:%d\tcol:%d", row, col);
    } while(board[row][col] != 0);

    updateBoard(row, col, board, cpu);
}

bool fullBoard(int board[][SIZE])
{
    bool full = true;
    for(int row = 0; row < SIZE; row++)
    {
        for(int col = 0; col < SIZE; col++)
        {
            if(board[row][col] == 0)
            {
                full = false;
                return full;
            }
        }
    }
    return full;
}
