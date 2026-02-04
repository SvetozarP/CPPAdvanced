#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    vector<string> matrix(10);
    for (int i = 0; i < 10; ++i) {
        cin >> matrix[i];
    }

    int time;
    cin >> time;

    vector<vector<int>> rustTime(10, vector<int>(10, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (matrix[i][j] == '!') {
                rustTime[i][j] = 0;
                q.push({ i, j });
            }
            else if (matrix[i][j] == '#') {
                rustTime[i][j] = -2; // Rust-resistant
            }
        }
    }

    int dr[] = { -1, 1, 0, 0 };
    int dc[] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int r = current.first;
        int c = current.second;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < 10 && nc >= 0 && nc < 10 && rustTime[nr][nc] == -1) {
                rustTime[nr][nc] = rustTime[r][c] + 1;
                q.push({ nr, nc });
            }
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (rustTime[i][j] != -2 && rustTime[i][j] != -1 && rustTime[i][j] <= time) {
                cout << '!';
            }
            else if (rustTime[i][j] == -2) {
                cout << '#';
            }
            else {
                cout << '.';
            }
        }
        cout << endl;
    }

    return 0;
}