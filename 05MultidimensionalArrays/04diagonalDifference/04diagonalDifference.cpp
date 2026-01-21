#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void readMatrix(vector<vector<int>>& matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> matrix[i][j];
        }
    }
}

int main()
{
    int rows, cols;
    cin >> rows;
    cols = rows; // The matrix is square
    vector<vector<int>> matrix(rows, vector<int>(cols));
    readMatrix(matrix, rows, cols);

	int primaryDiagonalSum = 0;
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < rows; ++i)
    {
        primaryDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][rows - 1 - i];
    }
    
	int diagonalDifference = abs(primaryDiagonalSum - secondaryDiagonalSum);
	cout << diagonalDifference << '\n';
	return 0;
    
}
