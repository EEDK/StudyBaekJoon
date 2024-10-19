#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int horseDx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int horseDy[] = {1, -1, 2, -2, 2, -2, 1, -1};

int K;
int W, H;

vector<vector<int>> Graph;
vector<vector<vector<int>>> visited;

struct State {
    int x, y, k, moves;
};

bool isValid(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

int bfs() {
    queue<State> q;
    q.push({0, 0, K, 0});
    visited[0][0][K] = 1;

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        if (curr.x == H - 1 && curr.y == W - 1) {
            return curr.moves;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (isValid(nx, ny) && !visited[nx][ny][curr.k] && Graph[nx][ny] == 0) {
                visited[nx][ny][curr.k] = 1;
                q.push({nx, ny, curr.k, curr.moves + 1});
            }
        }

        if (curr.k > 0) {
            for (int i = 0; i < 8; ++i) {
                int nx = curr.x + horseDx[i];
                int ny = curr.y + horseDy[i];

                if (isValid(nx, ny) && !visited[nx][ny][curr.k - 1] && Graph[nx][ny] == 0) {
                    visited[nx][ny][curr.k - 1] = 1;
                    q.push({nx, ny, curr.k - 1, curr.moves + 1});
                }
            }
        }
    }
    return -1;
}


int main() {
    FASTIO

    cin >> K;
    cin >> W >> H;
    Graph.resize(H, vector<int>(W, 0));
    visited.resize(H, vector<vector<int>>(W, vector<int>(K + 1, 0)));

    FOR(i, H) {
        FOR(j, W) {
            cin >> Graph[i][j];
        }
    }

    cout << bfs() << endl;

    return 0;
}