#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int N, M, K;

bool IsRange(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int BFS(const vector<vector<int>>& Graph, vector<vector<bool>>& Visited, pair<int, int> Pos)
{
    Visited[Pos.first][Pos.second] = true;

    queue<pair<int, int>> Queue;
    Queue.push(Pos);

    int size = 1;

    while (!Queue.empty())
    {
        int x = Queue.front().first;
        int y = Queue.front().second;
        Queue.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (IsRange(nx, ny) && Graph[nx][ny] == 1 && !Visited[nx][ny])
            {
                Queue.push({nx, ny});
                Visited[nx][ny] = true;
                size += 1;
            }
        }
    }

    return size;
}

int main()
{
    FASTIO

    cin >> N >> M >> K;

    vector<vector<int>> Graph(N, vector<int>(M, 0));
    vector<vector<bool>> Visited(N, vector<bool>(M, false));

    FOR(i, K)
    {
        int r, c;
        cin >> r >> c;

        Graph[r - 1][c - 1] = 1;
    }

    int answer = INT_MIN;
    FOR(i, N)
    {
        FOR(j, M)
        {
            if (Graph[i][j] == 1 && !Visited[i][j])
            {
                int newSize = BFS(Graph, Visited, {i, j});

                if (newSize > answer)
                {
                    swap(newSize, answer);
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}
