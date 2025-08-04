#include <stdio.h>
#include <stdlib.h>

#include "tictactoe.h"

void printBoard(int board[][SIZE])
{
    char element;

    for(int i = 0; i < SIZE; i++)
    {    
        putchar('\t');
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
            printf("\t- - - - -\n");
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
        coordinates->msg = "Invalid Coordinates. They doesn't exist.\n\0";
        return;
    }

    else if(board[row][col] != 0)
    {    
        coordinates->value = false;
        coordinates->msg = "Invalid Coordinates. The cell is already occupied.\n\0"; 
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
    int available = 0;

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(board[i][j] == 0) available++;
        }
    }
    
    struct cell cells[available];

    int index = 0;
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(board[i][j] == 0)
            {
                cells[index].row = i;
                cells[index].col = j;
                index++;
            }
        }
    }

    int random_cell = rand() % ((index - 1) - 0 + 1) + 0;
    updateBoard(cells[random_cell].row, cells[random_cell].col, board, cpu);
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
