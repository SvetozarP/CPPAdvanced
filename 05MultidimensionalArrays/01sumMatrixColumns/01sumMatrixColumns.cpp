#include <iostream>
#include <vector>

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
	cin >> rows >> cols;
	vector<vector<int>> matrix(rows, vector<int>(cols));
    readMatrix(matrix, rows, cols);
    for (int j = 0; j < cols; ++j)
    {
        int columnSum = 0;
        for (int i = 0; i < rows; ++i)
        {
            columnSum += matrix[i][j];
        }
        cout << columnSum << '\n';
    }
    cout << endl;
	return 0;
}
