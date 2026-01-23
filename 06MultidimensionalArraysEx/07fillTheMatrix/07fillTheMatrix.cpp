#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void fillMatrixPatternA(vector<vector<int>>& matrix, int n)
{
	int number = 1;
	for (int col = 0; col < n; ++col)
	{
		for (int row = 0; row < n; ++row)
		{
			matrix[row][col] = number++;
		}
	}
}

void fillMatrixPatternB(vector<vector<int>>& matrix, int n)
{
	int number = 1;
	for (int col = 0; col < n; ++col)
	{
		if (col % 2 == 0)
		{
			for (int row = 0; row < n; ++row)
			{
				matrix[row][col] = number++;
			}
		}
		else
		{
			for (int row = n - 1; row >= 0; --row)
			{
				matrix[row][col] = number++;
			}
		}
	}
}

void printMatrix(const vector<vector<int>>& matrix, int n)
{
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
}

int main()
{
	string input;
	getline(cin, input);
	istringstream iss(input);
	int rows, cols;
	char pattern;
	char comma;
	iss >> rows >> comma >> pattern;

	cols = rows;

	vector<vector<int>> matrix(rows, vector<int>(cols));
	switch (pattern)
	{
	case 'A':
		fillMatrixPatternA(matrix, rows);
		break;
	case 'B':
		fillMatrixPatternB(matrix, rows);
		break;
	default:
		cout << "Invalid pattern" << endl;
		return 1;
	}
	printMatrix(matrix, rows);
	return 0;
}
