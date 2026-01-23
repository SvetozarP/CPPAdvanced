#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void readMatrix(vector<vector<char>>& matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        string line;
        getline(cin >> ws, line);
        istringstream iss(line);
        for (int j = 0; j < cols; ++j)
        {
            iss >> matrix[i][j];
        }
    }
}

void count2x2Squares(const vector<vector<char>>& matrix, int rows, int cols)
{
    int count = 0;
    for (int i = 0; i < rows - 1; ++i)
    {
        for (int j = 0; j < cols - 1; ++j)
        {
            char current = matrix[i][j];
            if (matrix[i][j + 1] == current &&
                matrix[i + 1][j] == current &&
                matrix[i + 1][j + 1] == current)
            {
                ++count;
            }
        }
    }
    cout << count << endl;
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;
	vector<vector<char>> matrix(rows, vector<char>(cols));
	readMatrix(matrix, rows, cols);
	count2x2Squares(matrix, rows, cols);
	return 0;
}
