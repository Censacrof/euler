#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

typedef vector<vector<int> > Board;


void echoBoard(const Board &b)
{
	cout << "\n";
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			cout << b[y][x] << " ";
			if ((x + 1) % 3 == 0)
				cout << " ";
		}
		if ((y + 1) % 3 == 0)
			cout << "\n";
		cout << "\n";
	}
}

bool checkRow(Board board, int y, int n)
{
	for (int i = 0; i < 9; i++)
		if (board[y][i] == n)
			return false;
	return true;
}

bool checkColumn(Board board, int x, int n)
{
	for (int i = 0; i < 9; i++)
		if (board[i][x] == n)
			return false;
	return true;
}

bool checkSquare(Board board, int x, int y, int n)
{
	int sx, ex, sy, ey;

	if (x < 3) { sx = 0; ex = 2; }
	else if (x < 6) { sx = 3; ex = 5; }
	else { sx = 6; ex = 8; }

	if (y < 3) { sy = 0; ey = 2; }
	else if (y < 6) { sy = 3; ey = 5; }
	else { sy = 6; ey = 8; }

	for (int y = sy; y <= ey; y++)
		for (int x = sx; x <= ex; x++)
			if (board[y][x] == n)
				return false;
	return true;
}


bool getRes(Board &board)
{
	//check all cells until i find an empty one
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (board[y][x] == 0) //empty cell
			{
				//cout << "empty cell at: " << x << ", " << y << "\n";

				for (int i = 1; i <= 9; i++)
				{
					if (checkRow(board, y, i) && checkColumn(board, x, i) && checkSquare(board, x, y, i))
					{
						//cout << "\tpossible value: " << i << "\n";
						int buff = board[y][x];
						
						board[y][x] = i;

						if (getRes(board))
							return true;
						else
							board[y][x] = buff;
					}
				}

				return false;
			}
		}
	}

	return true;
}


int main()
{
	ifstream file("sudoku.txt");

	int sum = 0;
	for (int j = 0; j < 50; j++)
	{
		Board board; //board[y][x]
		string line;
		for (int i = 0; i < 10 && getline(file, line); i++)
		{
			if (i == 0)
				continue;

			vector<int> row;
			
			for (int j = 0; j < 9; j++)
			{
				int c;
				string buff = ""; buff += line[j];
				stringstream(buff) >> c;
				row.push_back(c);
			}

			board.push_back(row);
		}

		getRes(board);

		cout << "\n\n------Board-" << j + 1 << "--------\n";
		echoBoard(board);

		int add; 
		stringstream ss;
		ss << board[0][0] << board[0][1] << board[0][2];
		ss >> add;

		cout << "sum = " << sum << " + " << add << " = " << sum + add << "\n";
		sum += add;


	}

	

	return 0;
}