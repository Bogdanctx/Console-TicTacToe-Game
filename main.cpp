// Let's create Tic Tac Toe in C++ (Console)

#include <iostream>
#include <ctime>
#include <random>

using namespace std;

void DrawBoard(short board[4][4])
{
	for (unsigned short i = 0; i < 3; i++, cout << '\n')
	{
		for (unsigned short j = 0; j < 3; j++)
		{
			if (board[i][j] == -1)
				cout << " _ ";
			else
			{
				if (board[i][j] == 0)
					cout << " x ";
				else
					cout << " 0 ";
			}
		}
	}

	return;
}

short CheckWinners(short board[4][4])
{
	// Checking each line
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != -1)
		return board[0][0];
	if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != -1)
		return board[1][0];
	if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != -1)
		return board[2][0];

	// Checking each column
	if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != -1)
		return board[0][0];
	if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != -1)
		return board[0][1];
	if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != -1)
		return board[0][2];

	// Checking each diagonal
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != -1)
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != -1)
		return board[0][2];

	// Checking for free positions
	for (unsigned short i = 0; i < 3; i++)
		for (unsigned short j = 0; j < 3; j++)
			if (board[i][j] == -1)
				return -1;
	return 2; // Tie
}

int main()
{
	srand(time(0));

	short board[4][4];
	char mark;
	bool player_mark;

	cout << "Play with x or 0: "; cin >> mark;

	(mark == 'x' ? player_mark = 0 : player_mark = 1);

	for (unsigned short i = 0; i < 3; i++)
		for (unsigned short j = 0; j < 3; j++)
			board[i][j] = -1;

	unsigned short position;
	short winner;
	
	do
	{
		system("cls");
		DrawBoard(board);

		cout << "Enter position to mark: "; cin >> position;

		if (board[(position / 10) - 1][(position % 10) - 1] == -1) // valid position
		{
			board[(position / 10) - 1][(position % 10) - 1] = player_mark;

			system("cls");
			DrawBoard(board);

			winner = CheckWinners(board);
			if (winner == player_mark)
			{
				cout << "You won!\n";
				return 0;
			}

			unsigned short free_positions[10], index = 0;

			for (unsigned short i = 0; i < 3; i++)
				for (unsigned short j = 0; j < 3; j++)
					if (board[i][j] == -1)
						free_positions[index++] = (i + 1) * 10 + (j + 1);

			unsigned short random_position = free_positions[rand() % index];

			board[(random_position / 10) - 1][(random_position % 10) - 1] = !player_mark; // enemy mark

			system("cls");
			DrawBoard(board);

			winner = CheckWinners(board);
			if (winner == !player_mark)
			{
				cout << "You lost!\n";
				return 0;
			}

			if (winner == 2)
			{
				cout << "TIE\n";
				return 0;
			}
		}

	} while (1);

	return 0;
}
