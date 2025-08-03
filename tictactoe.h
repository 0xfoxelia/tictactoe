#define SIZE 3

struct errHandling
{
  bool value;
  char* msg;
};

/*
struct slotPoints
{
  int row;
  int col;
};
*/

void printBoard(int board[][SIZE]);
void clearInputBuffer();
void checkCoordinates(int row, int col, int board[][SIZE], struct errHandling *coordinates);
void updateBoard(int row, int col, int board[][SIZE], int activePlayer);
void clearScreen();
bool checkWin(int board[][SIZE], int player);
void cpuChoice(int board[][SIZE], int cpu);
bool fullBoard(int board[][SIZE]);
