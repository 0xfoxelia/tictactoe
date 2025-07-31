#define SIZE 3

void printBoard(int board[][SIZE]);
void clearInputBuffer();
bool checkCoordinates(int row, int col, int board[][SIZE]);
void updateBoard(int row, int col, int board[][SIZE]);
void clearScreen();
bool checkWin(int board[][SIZE], int player);
