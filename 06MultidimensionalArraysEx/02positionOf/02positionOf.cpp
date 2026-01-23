#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

void findElementPositions(const vector<vector<int>>& matrix, int x) {
	bool found = false;
	for (size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix[i].size(); ++j) {
			if (matrix[i][j] == x) {
				cout << i << " " << j << endl;
				found = true;
			}
		}
	}
	if (!found) {
		cout << "not found" << endl;
	}
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;
	vector<vector<int>> matrix(rows, vector<int>(cols));
	readMatrix(matrix, rows, cols);
	int x;
	cin >> x;
	findElementPositions(matrix, x);
	return 0;
}