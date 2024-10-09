#include <bits/stdc++.h>
using namespace std;

const int N = 5;
int answer = 0;
char Graph[N][N];
bool visited[N][N];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool IsValid(int y, int x) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

bool isConnected(vector<pair<int, int>>& selected) {
    queue<pair<int, int>> q;
    bool tempVisited[N][N] = {false};

    q.push(selected[0]);
    tempVisited[selected[0].first][selected[0].second] = true;
    int connectedCount = 1;

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (IsValid(ny, nx) && !tempVisited[ny][nx]) {
                for (auto& p : selected) {
                    if (p.first == ny && p.second == nx) {
                        tempVisited[ny][nx] = true;
                        q.push({ny, nx});
                        connectedCount++;
                        break;
                    }
                }
            }
        }
    }

    return connectedCount == 7;
}

void Backtrack(int idx, int dasomCount, vector<pair<int, int>>& selected) {
    if (selected.size() == 7) {
        if (dasomCount >= 4 && isConnected(selected)) {
            answer++;
        }
        return;
    }

    for (int i = idx; i < N * N; i++) {
        int y = i / N;
        int x = i % N;

        if (!visited[y][x]) {
            visited[y][x] = true;
            selected.push_back({y, x});

            if (Graph[y][x] == 'S') {
                Backtrack(i + 1, dasomCount + 1, selected);
            } else {
                Backtrack(i + 1, dasomCount, selected);
            }

            selected.pop_back();
            visited[y][x] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Graph[i][j];
        }
    }

    vector<pair<int, int>> selected;
    Backtrack(0, 0, selected);

    cout << answer << "\n";

    return 0;
}
