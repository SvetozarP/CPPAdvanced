#include <iostream>
#include <vector>
#include <numeric>

bool isPrime(int n) {
    if (n <= 0) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    using namespace std;

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    long long sumOfPrimes = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool onMainDiagonal = (i == j);
            bool onAntiDiagonal = (i + j == n - 1);

            if (!onMainDiagonal && !onAntiDiagonal) {
                if (i > j && i + j > n - 1) { // Below both diagonals
                    if (isPrime(matrix[i][j])) {
                        sumOfPrimes += matrix[i][j];
                    }
                }
            }
        }
    }

    cout << sumOfPrimes << endl;

    return 0;
}