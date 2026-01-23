#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>
#include <cmath>

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

void findMaximalSumSubmatrix(const vector<vector<int>>& matrix, int rows, int cols, int sizeR, int sizeC) {
	int maxSum = INT_MIN;
	int maxRow = 0;
	int maxCol = 0;
	for (int i = 0; i <= rows - sizeR; ++i) {
		for (int j = 0; j <= cols - sizeC; ++j) {
			int currentSum = 0;
			for (int r = 0; r < sizeR; ++r) {
				for (int c = 0; c < sizeC; ++c) {
					currentSum += matrix[i + r][j + c];
				}
			}
			if (currentSum > maxSum) {
				maxSum = currentSum;
				maxRow = i;
				maxCol = j;
			}
		}
	}
	cout << "Sum = " << maxSum << endl;
	for (int r = 0; r < sizeR; ++r) {
		for (int c = 0; c < sizeC; ++c) {
			cout << matrix[maxRow + r][maxCol + c] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;
	vector<vector<int>> matrix(rows, vector<int>(cols));
	readMatrix(matrix, rows, cols);
	int sizeR = 3;
	int sizeC = 3;
	findMaximalSumSubmatrix(matrix, rows, cols, sizeR, sizeC);
	return 0;
}