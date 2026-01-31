#include <iostream>

using namespace std;

int** createDynamicArray(int rows, int cols) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }
    return arr;
}

void fillDynamicArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> arr[i][j];
        }
    }
}

void printPartialArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << (j == cols - 1 ? "" : " ");
        }
        cout << endl;
    }
}

void deleteDynamicArray(int** arr, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int N, M;
    cin >> N >> M;

    int** originalArray = createDynamicArray(N, M);
    void (*filler)(int**, int, int) = &fillDynamicArray;
    filler(originalArray, N, M);

    int R, C;
    cin >> R >> C;

    void (*printer)(int**, int, int) = &printPartialArray;
    printer(originalArray, R, C);

    void (*deleter)(int**, int) = &deleteDynamicArray;
    deleter(originalArray, N);

    return 0;
}