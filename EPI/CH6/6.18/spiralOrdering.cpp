#include <iostream>
#include <vector>
using namespace std;

enum Direction {UP, DOWN, LEFT, RIGHT};

void switchDirection(Direction& d)
{
	if(d == UP)
		d = RIGHT;
	else if(d == RIGHT)
		d = DOWN;
	else if(d == DOWN)
		d = LEFT;
	else // IF (D == LEFT)
		d = UP;
}

bool canMove(int row, int col, const vector<vector<int> >& matrix)
{
	// can move right
	if(col + 1 < matrix[0].size() && matrix[row][col + 1] != -1)
		return true;

	// can move left
	if(col - 1 >= 0 && matrix[row][col - 1] != -1)
		return true;

	// can move up
	if(row - 1 >= 0 && matrix[row - 1][col] != -1)
		return true;

	// can move down
	if(row + 1 < matrix.size() && matrix[row + 1][col] != -1)
		return true;

	return false;
}

void moveInDirection(Direction d, int& row, int& col, vector<vector<int> >& matrix)
{
	switch(d)
	{
		case UP:
			row--;
			while(row >= 0 && matrix[row][col] != -1)
			{
				cout << matrix[row][col] << " ";
				matrix[row][col] = -1;
				row--;
			}
			row++;
			cout << endl;

		break;

		case DOWN:
			row++;
			while(row < matrix.size() && matrix[row][col] != -1)
			{
				cout << matrix[row][col] << " ";
				matrix[row][col] = -1;
				row++;
			}
			row--;
			cout << endl;

		break;

		case RIGHT:
			col++;
			while(col < matrix[0].size() && matrix[row][col] != -1)
			{
				cout << matrix[row][col] << " ";
				matrix[row][col] = -1;
				col++;
			}
			col--;
			cout << endl;

		break;

		case LEFT:
			col--;
			while(col >= 0 && matrix[row][col] != -1)
			{
				cout << matrix[row][col] << " ";
				matrix[row][col] = -1;
				col--;
			}
			col++;
			cout << endl;

		break;
	}
}

void spiralOrdering(vector<vector<int> >& matrix)
{
	Direction dir = RIGHT;
	int row = 0;
	int col = 0;

	cout << matrix[row][col] << " ";
	matrix[row][col] = -1;

	while(canMove(row, col, matrix))
	{
		moveInDirection(dir, row, col, matrix);
		switchDirection(dir);
	}
}

int main()
{
	vector<vector<int> > A = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	spiralOrdering(A);

	return 0;
}