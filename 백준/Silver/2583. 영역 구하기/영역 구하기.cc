#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int BFS(vector<vector<int>> Graph, vector<vector<int>>& Visited, pair<int, int> pos)
{
    queue<pair<int, int>> Queue;
    Queue.push(pos);

    int sum = 0;

    while (!Queue.empty())
    {
        int x = Queue.front().first;
        int y = Queue.front().second;
        Queue.pop();

        if (Visited[x][y]) continue;

        Visited[x][y] = 1;
        sum++;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= Graph.size() || ny >= Graph[0].size()) continue;

            if (Graph[nx][ny] == 1 || Visited[nx][ny] != 0) continue;

            Queue.push({nx, ny});
        }
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N, K;

    cin >> M >> N >> K;

    vector<vector<int>> Graph(M, vector<int>(N, 0));
    vector<vector<int>> Visited(M, vector<int>(N, 0));

    for (int i = 0; i < K; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; ++y)
        {
            for (int x = x1; x < x2; ++x)
            {
                Graph[y][x] = 1;
            }
        }
    }

    vector<int> Result;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Graph[i][j] == 0 && Visited[i][j] == 0)
            {
                Result.push_back(BFS(Graph, Visited, {i, j}));
            }
        }
    }


    cout << Result.size() << "\n";

    sort(Result.begin(), Result.end());

    for (int i = 0; i < Result.size(); i++)
    {
        cout << Result[i] << " ";
    }

    cout << "\n";


    return 0;
}
