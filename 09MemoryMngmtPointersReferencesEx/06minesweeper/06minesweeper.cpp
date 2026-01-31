#include <iostream>

using namespace std;

void readMatrix(char** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
}

int countMines(char** matrix, int r, int c, int rows, int cols) {
    int mineCount = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int newR = r + i;
            int newC = c + j;
            if (newR >= 0 && newR < rows && newC >= 0 && newC < cols) {
                if (matrix[newR][newC] == '!') {
                    mineCount++;
                }
            }
        }
    }
    return mineCount;
}

void processMatrix(char** inputMatrix, int** outputMatrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int (*counter)(char**, int, int, int, int) = &countMines;
            outputMatrix[i][j] = counter(inputMatrix, i, j, rows, cols);
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void deleteMatrix(char** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int N, M;
    cin >> N >> M;

    char** inputMatrix = new char* [N];
    for (int i = 0; i < N; ++i) {
        inputMatrix[i] = new char[M];
    }

    int** outputMatrix = new int* [N];
    for (int i = 0; i < N; ++i) {
        outputMatrix[i] = new int[M];
    }

    void (*read_func)(char**, int, int) = &readMatrix;
    read_func(inputMatrix, N, M);

    void (*process_func)(char**, int**, int, int) = &processMatrix;
    process_func(inputMatrix, outputMatrix, N, M);

    void (*print_func)(int**, int, int) = &printMatrix;
    print_func(outputMatrix, N, M);

    void (*delete_char_matrix)(char**, int) = &deleteMatrix;
    delete_char_matrix(inputMatrix, N);

    void (*delete_int_matrix)(int**, int) = &deleteMatrix;
    delete_int_matrix(outputMatrix, N);

    return 0;
}