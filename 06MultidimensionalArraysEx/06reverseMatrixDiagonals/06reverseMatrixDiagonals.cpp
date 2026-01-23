#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void readMatrix(vector<vector<int>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        string line;
        getline(cin >> ws, line);

        istringstream iss(line);
        for (int j = 0; j < cols; ++j) {
            iss >> matrix[i][j];
        }
    }
}

void printReversedDiagonals(const vector<vector<int>>& matrix, int rows, int cols) {
    for (int sum = (rows - 1) + (cols - 1); sum >= 0; --sum) {
        vector<int> currentDiagonal;

        int r_start = max(0, sum - (cols - 1));
        
        int r_end = min(rows - 1, sum);

        for (int r = r_start; r <= r_end; ++r) {
            int c = sum - r;
        
            currentDiagonal.push_back(matrix[r][c]);
        }

        reverse(currentDiagonal.begin(), currentDiagonal.end());

        for (int val : currentDiagonal) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    readMatrix(matrix, rows, cols);

    printReversedDiagonals(matrix, rows, cols);

    return 0;
}