#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<vector<int>> readMatrix() {
    int rows;
    cin >> rows;

    vector<vector<int>> matrix(rows);

    
    for (int i = 0; i < rows; ++i) {
        string line;
        getline(cin >> ws, line);

        istringstream iss(line); 
        int num;
        while (iss >> num) { 
            matrix[i].push_back(num);
        }
    }
    return matrix;
}

bool areMatricesEqual(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB) {
    if (matrixA.size() != matrixB.size()) {
        return false;
    }

    if (matrixA.empty()) {
        return true;
    }

    for (size_t i = 0; i < matrixA.size(); ++i) {
        if (matrixA[i].size() != matrixB[i].size()) {
            return false;
        }
        for (size_t j = 0; j < matrixA[i].size(); ++j) {
            if (matrixA[i][j] != matrixB[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> matrixA = readMatrix();
    vector<vector<int>> matrixB = readMatrix();

    if (areMatricesEqual(matrixA, matrixB)) {
        cout << "equal" << endl;
    }
    else {
        cout << "not equal" << endl;
    }

    return 0;
}