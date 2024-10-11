#include <iostream>
#include <vector>

using namespace std;

void explode(vector<vector<char>>& board, vector<vector<char>>& bombs, int r, int c) {
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            bombs[y][x] = 'O';
        }
    }

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (board[y][x] == 'O') {
                bombs[y][x] = '.';
                for (auto [i, j] : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                    int ny = y + i;
                    int nx = x + j;
                    if (ny >= 0 && ny < r && nx >= 0 && nx < c) {
                        bombs[ny][nx] = '.';
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int r, c, n;
    cin >> r >> c >> n;

    vector<vector<char>> board(r, vector<char>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }

    if (n <= 1) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << board[i][j];
            }
            cout << "\n";
        }
        return 0;
    }

    if (n % 2 == 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << 'O';
            }
            cout << "\n";
        }
        return 0;
    }

    vector<vector<char>> bombs1(r, vector<char>(c, 'O'));
    explode(board, bombs1, r, c);

    vector<vector<char>> bombs2(r, vector<char>(c, 'O'));
    explode(bombs1, bombs2, r, c);

    if (n % 4 == 3) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << bombs1[i][j];
            }
            cout << "\n";
        }
    } else if (n % 4 == 1) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << bombs2[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
