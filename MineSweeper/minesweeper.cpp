
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int board[20][20] = { 0 }; //initializing the board with 0s
int no_of_mines = 0; //initializing number of mines

void chain_step(int x, int y);
void chain_move(int x, int y);

void count_adjacent(int x, int y) //this function takes a cell which has a mine and accordingly adds +1 to adjacent cells
{
	if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] != -1)
	{
		board[x - 1][y - 1]++;
	}
	if (y - 1 >= 0 && board[x][y - 1] != -1)
	{
		board[x][y - 1]++;
	}
	if (x + 1 <= 9 && y - 1 >= 0 && board[x + 1][y - 1] != -1)
	{
		board[x + 1][y - 1]++;
	}
	//
	if (x - 1 >= 0 && board[x - 1][y] != -1)
	{
		board[x - 1][y]++;
	}
	if (x + 1 <= 9 && board[x + 1][y] != -1)
	{
		board[x + 1][y]++;
	}
	//
	if (x - 1 >= 0 && y + 1 <= 9 && board[x - 1][y + 1] != -1)
	{
		board[x - 1][y + 1]++;
	}
	if (y + 1 <= 9 && board[x][y + 1] != -1)
	{
		board[x][y + 1]++;
	}
	if (x + 1 <= 9 && y + 1 <= 9 && board[x + 1][y + 1] != -1)
	{
		board[x + 1][y + 1]++;
	}
}

void convert_table() //this function converts the table into a more output friendly form for dispBoard()
{
	int x = 10, y = 10;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (board[i][j] >= 0)
				board[i][j] -= 10;
		}
	}
}

void random_Board() //this function puts in random mines in the table and calls other require function to initialize the game
{
	srand(time(0));
	int i = no_of_mines;

	int x, y;
	while (i != 0)
	{
		cout << 1;
		x = rand() % 10;
		y = rand() % 10;

		if (board[x][y] == -1)
		{

		}
		else
		{
			board[x][y] = -1;
			count_adjacent(x, y);
		}
		i--;
	}

	convert_table();
}

void chain_move(int x, int y) // recursive function required for chain_step()
{
	if (board[x][y] < -1)
	{
		if (board[x][y] == -10)
		{
			board[x][y] += 10;
			chain_step(x, y);
		}
		else
			board[x][y] += 10;
	}
}

void chain_step(int x, int y) //function to find all adjacent cells with no mine around
{
	if (x - 1 >= 0 && y - 1 >= 0)
		chain_move(x - 1, y - 1);
	if (y - 1 >= 0)
		chain_move(x, y - 1);
	if (x + 1 <= 9 && y - 1 >= 0)
		chain_move(x + 1, y - 1);
	//
	if (x - 1 >= 0)
		chain_move(x - 1, y);
	if (x + 1 <= 9)
		chain_move(x + 1, y);
	//
	if (x - 1 >= 0 && y + 1 <= 9)
		chain_move(x - 1, y + 1);
	if (y + 1 <= 9)
		chain_move(x, y + 1);
	if (x + 1 <= 9 && y + 1 <= 9)
		chain_move(x + 1, y + 1);
	return;
}

void move(int x, int y) // function for player moves
{
	if (board[x][y] == -1)
	{
		cout << "\nYou stepped on a mine. Game over\n\n";
		exit(0);
	}

	if (board[x][y] < -1)
	{
		if (board[x][y] == -10) 
		{
			board[x][y] += 10;
			chain_step(x, y); //this is called to chain the steps required to show all the adjacent cells which have no mine around
		}
		else
			board[x][y] += 10;
	}
}

void dispBoard() //this displays the table in the required manner
{
	int x = 10, y = 10;
	int count = 0;

	cout << "\t";

	for (int i = 0; i < x; i++)
		cout << i << "\t";
	cout << endl << endl << endl << "\t";
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (board[i][j] < 0)
			{
				cout << "-\t";
			}
			else
			{
				count++;
				cout << board[i][j] << "\t";
			}
		}
		cout << "\t" <<i;
		cout << endl;
		cout << "\t";
	}
	if (count == 100 - no_of_mines)
	{
		cout << "\nCongratulations. You won!\n\n";
		exit(0);
	}
}

void play() //to start the game
{
	random_Board();
	while (1)
	{
		system("CLS"); //it clears the console
		cout << "Number of mines = " << no_of_mines << "\n\n";

		dispBoard();
		int x, y;
		cout << "\n\nInput row and column number:\n";
		cin >> x >> y;
		move(x, y);
	}
}

int main()
{
	cout << "Input number of mines (minimum = 1 & maximum = 10) : ";
	cin >> no_of_mines;

	if (no_of_mines < 1 || no_of_mines > 10)
	{
		cout << "Invalid input. Restarting\n\n";
		main();
	}
	random_Board();
	play();

	return 0;
}