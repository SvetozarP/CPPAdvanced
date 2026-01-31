#include <iostream>
#include <sstream>

using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int* rows_ptr, int* cols_ptr) {
    int rows;
    cin >> rows;
    *rows_ptr = rows;

    string line;
    getline(cin, line); // Consume the newline after reading rows

    int maxCols = 0;
    for (int i = 0; i < rows; ++i) {
        getline(cin, line);
        int currentCols = 0;
        int num = 0;
        bool inNumber = false;
        for (char c : line) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
                inNumber = true;
            }
            else {
                if (inNumber) {
                    matrix[i][currentCols++] = num;
                    num = 0;
                    inNumber = false;
                }
            }
        }
        if (inNumber) { // Add the last number if the line doesn't end with a space
            matrix[i][currentCols++] = num;
        }
        if (currentCols > maxCols) {
            maxCols = currentCols;
        }
    }
    *cols_ptr = maxCols;
}

bool compareMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int rows1, int cols1,
    int matrix2[MAX_SIZE][MAX_SIZE], int rows2, int cols2) {

    int* r1_ptr = &rows1;
    int* c1_ptr = &cols1;
    int* r2_ptr = &rows2;
    int* c2_ptr = &cols2;

    if (*r1_ptr != *r2_ptr || *c1_ptr != *c2_ptr) {
        return false;
    }

    for (int i = 0; i < *r1_ptr; ++i) {
        for (int j = 0; j < *c1_ptr; ++j) {
            int* val1_ptr = &matrix1[i][j];
            int* val2_ptr = &matrix2[i][j];
            if (*val1_ptr != *val2_ptr) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE];
    int rows1, cols1;
    void (*read_func)(int[MAX_SIZE][MAX_SIZE], int*, int*) = &readMatrix;
    read_func(matrix1, &rows1, &cols1);

    int matrix2[MAX_SIZE][MAX_SIZE];
    int rows2, cols2;
    read_func(matrix2, &rows2, &cols2);

    bool (*compare_func)(int[MAX_SIZE][MAX_SIZE], int, int, int[MAX_SIZE][MAX_SIZE], int, int) = &compareMatrices;

    if (compare_func(matrix1, rows1, cols1, matrix2, rows2, cols2)) {
        cout << "equal" << endl;
    }
    else {
        cout << "not equal" << endl;
    }

    return 0;
}