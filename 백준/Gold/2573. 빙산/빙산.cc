#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

void Melt(vector<vector<int>>& Graph, int N, int M)
{
    vector<vector<int>> Temp(N, vector<int>(M, 0));

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            if (Graph[x][y] != 0)
            {
                int cnt = 0;
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                    if (Graph[nx][ny] == 0)
                    {
                        cnt++;
                    }
                }
                Temp[x][y] = cnt;
            }
        }
    }

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            if (Graph[x][y] - Temp[x][y] > 0)
            {
                Graph[x][y] -= Temp[x][y];
            }
            else
            {
                Graph[x][y] = 0;
            }
        }
    }
}

void BFS(vector<vector<int>>& Graph, vector<vector<bool>>& Visited, int N, int M, int startX, int startY)
{
    queue<pair<int, int>> Queue;
    Queue.push({startX, startY});
    Visited[startX][startY] = true;

    while (!Queue.empty())
    {
        int x = Queue.front().first;
        int y = Queue.front().second;
        Queue.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (Visited[nx][ny] || Graph[nx][ny] == 0) continue;

            Visited[nx][ny] = true;
            Queue.push({nx, ny});
        }
    }
}

int CountIcebergComponents(vector<vector<int>>& Graph, int N, int M)
{
    vector<vector<bool>> Visited(N, vector<bool>(M, false));
    int components = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Graph[i][j] != 0 && !Visited[i][j])
            {
                BFS(Graph, Visited, N, M, i, j);
                components++;
            }
        }
    }

    return components;
}

bool AllMelted(const vector<vector<int>>& Graph, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Graph[i][j] > 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> Graph(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Graph[i][j];
        }
    }

    int years = 0;
    while (true)
    {
        int components = CountIcebergComponents(Graph, N, M);

        if (components >= 2)
        {
            cout << years << "\n";
            return 0;
        }

        if (AllMelted(Graph, N, M))
        {
            cout << 0 << "\n";
            return 0;
        }

        Melt(Graph, N, M);
        years++;
    }

    return 0;
}
