#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF (~0U >> 2)
#define PB push_back
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int N, M;
vvi Graph;

int BFS()
{
    vvi Visited(N, vector<int>(M, -1));

    queue<pii> Queue;
    Queue.push({0, 0});
    Visited[0][0] = 1;

    while (!Queue.empty())
    {
        int x = Queue.front().first;
        int y = Queue.front().second;
        Queue.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && Visited[nx][ny] == -1 && Graph[nx][ny] == 1)
            {
                Visited[nx][ny] = Visited[x][y] + 1;
                Queue.push({nx, ny});
            }
        }
    }

    return Visited[N - 1][M - 1];
}

int main()
{
    FASTIO
    cin >> N >> M;

    Graph.resize(N, vi(M, 0));

    FOR(i, N)
    {
        string input;
        cin >> input;

        FOR(j, M)
        {
            Graph[i][j] = input[j] - '0';
        }
    }

    cout << BFS() << endl;

    return 0;
}
