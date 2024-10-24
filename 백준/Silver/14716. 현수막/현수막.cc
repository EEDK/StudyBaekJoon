#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back

typedef pair<int, int> pii;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

vector<vector<int>> Graph;

int M, N;

bool IsRange(pii Pos) {
    int x = Pos.first;
    int y = Pos.second;

    return (x >= 0 && x < M && y >= 0 && y < N);
}

void DFS(pii Pos, vector<vector<bool>>& Visited) {
    int x = Pos.first;
    int y = Pos.second;
    Visited[x][y] = true;

    FOR(i, 8) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (IsRange({nx, ny}) && Graph[nx][ny] == 1 && !Visited[nx][ny]) {
            DFS({nx, ny}, Visited);
        }
    }
}

int main() {
    FASTIO

    cin >> M >> N;
    vector<vector<bool>> Visited;

    Graph.resize(M, vector<int>(N, 0));
    Visited.resize(M, vector<bool>(N, false));

    FOR(i, M) {
        FOR(j, N) {
            cin >> Graph[i][j];
        }
    }

    int answer = 0;

    FOR(i, M) {
        FOR(j, N) {
            if (Graph[i][j] == 1 && !Visited[i][j]) {
                DFS({i, j}, Visited);
                answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}
