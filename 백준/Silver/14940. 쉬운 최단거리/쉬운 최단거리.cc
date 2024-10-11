#include <bits/stdc++.h>

using namespace std;

int n, m;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

bool IsValid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    vector<vector<int>> Graph(n, vector<int>(m, 0));
    vector<vector<int>> Dist(n, vector<int>(m, -1));
    pair<int, int> TargetPos;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Graph[i][j];
            if (Graph[i][j] == 2)
            {
                TargetPos = {i, j};
                Dist[i][j] = 0;
            }
        }
    }

    queue<pair<int, int>> Queue;
    Queue.push(TargetPos);

    while (!Queue.empty())
    {
        int x = Queue.front().first;
        int y = Queue.front().second;
        Queue.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (IsValid(nx, ny) && Graph[nx][ny] == 1 && Dist[nx][ny] == -1)
            {
                Dist[nx][ny] = Dist[x][y] + 1;
                Queue.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Graph[i][j] == 0)
                cout << 0 << " ";
            else
                cout << Dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
