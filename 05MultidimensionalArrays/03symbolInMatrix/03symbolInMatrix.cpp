#include <iostream>
#include <vector>
#include <string>

using namespace std;

void readMatrix(vector<vector<char>>& matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        string row_str;
        cin >> row_str;
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = row_str[j];
        }
    }
}


int main()
{
    int rows, cols;
    cin >> rows;
    cols = rows; // The matrix is square
    vector<vector<char>> matrix(rows, vector<char>(cols));
    readMatrix(matrix, rows, cols);
	char symbol;
    cin >> symbol;
    
    bool found = false;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] == symbol)
            {
                cout << "(" << i << ", " << j << ")" << endl;
                found = true;
                break;
            }
        }
        if (found)
        {
            break;
        }
    }
    
    if (!found)
    {
        cout << symbol << " does not occur in the matrix" << endl;
    }
    
	return 0;
}