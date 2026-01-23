#include <iostream>
#include <vector>
#include <string>

using namespace std;

void fillSnakeMatrix(vector<vector<char>>& matrix, const string& snake)
{
	int rows = matrix.size();
	int cols = matrix[0].size();
	int snakeIndex = 0;
	for (int i = 0; i < rows; ++i)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < cols; ++j)
			{
				matrix[i][j] = snake[snakeIndex];
				snakeIndex = (snakeIndex + 1) % snake.length();
			}
		}
		else
		{
			for (int j = cols - 1; j >= 0; --j)
			{
				matrix[i][j] = snake[snakeIndex];
				snakeIndex = (snakeIndex + 1) % snake.length();
			}
		}
	}
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;
	
	string snake;
	cin >> snake;
	
	vector<vector<char>> matrix(rows, vector<char>(cols));
	
	fillSnakeMatrix(matrix, snake);

	for (const auto& row : matrix)
	{
		for (const auto& ch : row)
		{
			cout << ch;
		}
		cout << endl;
	}
	return 0;
}
