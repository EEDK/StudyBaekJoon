#include <bits/stdc++.h>

using namespace std;

static int dx[] = {-1, 0, 1, 0};
static int dy[] = {0, -1, 0, 1};

void BFS(vector<vector<int>> Graph, vector<vector<bool>>& Visited, pair<int, int> pos)
{
    Visited[pos.first][pos.second] = true;
    queue<pair<int, int>> queue;

    queue.push(pos);

    while (!queue.empty())
    {
        int x = queue.front().first;
        int y = queue.front().second;
        queue.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= Graph.size() || ny >= Graph[0].size() || nx < 0 || ny < 0) continue;

            if (Graph[nx][ny] == 1 && !Visited[nx][ny])
            {
                queue.push({nx, ny});
                Visited[nx][ny] = true;
            }
        }
    }
}


int main()
{
    int T;
    cin >> T;

    vector<int> Answer;

    for (int i = 0; i < T; i++)
    {
        int M, N, K;

        cin >> M >> N >> K;
        vector<vector<int>> Graph(M, vector<int>(N, 0));
        vector<vector<bool>> Visited(M, vector<bool>(N, false));

        for (int j = 0; j < K; j++)
        {
            int x, y;
            cin >> x >> y;
            Graph[x][y] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (Graph[i][j] == 1 && !Visited[i][j])
                {
                    BFS(Graph, Visited, {i, j});
                    cnt++;
                }
            }
        }

        Answer.push_back(cnt);
    }

    for (int item : Answer)
    {
        cout << item << "\n";
    }

    return 0;
}
