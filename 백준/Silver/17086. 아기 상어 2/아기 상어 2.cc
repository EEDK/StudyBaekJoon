#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N;
int M;

bool IsRange(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int BFS(const vector<vector<int>>& Graph, pair<int, int> StartPos)
{
    int x = StartPos.first;
    int y = StartPos.second;
    vector<vector<int>> Visited(N, vector<int>(M, 0));
    Visited[x][y] = 1;

    queue<pair<int, int>> Queue;
    Queue.push(StartPos);

    while (!Queue.empty())
    {
        int x = Queue.front().first;
        int y = Queue.front().second;
        Queue.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (IsRange(nx, ny) && Visited[nx][ny] == 0)
            {
                if (Graph[nx][ny] == 1) return Visited[x][y];
                Visited[nx][ny] = Visited[x][y] + 1;

                Queue.push({nx, ny});
            }
        }
    }
    return 0;
}


int main()
{
    cin >> N >> M;

    vector<vector<int>> Graph(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Graph[i][j];
        }
    }

    int MaxRange = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Graph[i][j] == 0)
            {
                MaxRange = max(MaxRange, BFS(Graph, {i, j}));
            }
        }
    }

    cout << MaxRange << "\n";

    return 0;
}
