#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back

typedef pair<int, int> pii;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int N, M, T;
vector<vector<int>> Graph;

pii GramPos;

int BFS(pii Start, pii Target, bool ignoreWalls = false) {
    vector<vector<int>> dist(N, vector<int>(M, INF));
    queue<pii> q;
    dist[Start.first][Start.second] = 0;
    q.push(Start);

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        FOR(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (Graph[nx][ny] == 1 && !ignoreWalls)
                    continue; // 벽 통과 불가
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return dist[Target.first][Target.second];
}

int main() {
    FASTIO

    cin >> N >> M >> T;

    Graph.resize(N, vector<int>(M, 0));

    FOR(i, N) {
        FOR(j, M) {
            cin >> Graph[i][j];
            if (Graph[i][j] == 2) {
                GramPos = {i, j};
            }
        }
    }

    int Normal = BFS({0, 0}, {N - 1, M - 1});

    int ToGram = BFS({0, 0}, GramPos);
    int GramToEnd = ToGram != INF ? BFS(GramPos, {N - 1, M - 1}, true) : INF;

    int Gram = ToGram + GramToEnd;

    int result = min(Normal, Gram);
    if (result <= T) {
        cout << result << endl;
    } else {
        cout << "Fail" << endl;
    }

    return 0;
}