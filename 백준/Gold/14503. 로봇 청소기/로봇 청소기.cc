#include <bits/stdc++.h>

using namespace std;

int N, M;
int r, c, d;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool IsRange(int y, int x)
{
    return (y >= 0 && y < N && x >= 0 && x < M);
}

int Clear(vector<vector<int>>& Graph, vector<vector<bool>>& Visited, int y, int x, int d)
{
    int cleaned_count = 0;

    while (true)
    {
        if (!Visited[y][x])
        {
            Visited[y][x] = true;
            cleaned_count++;
        }

        bool found = false;

        for (int i = 0; i < 4; i++)
        {
            d = (d + 3) % 4;
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (IsRange(ny, nx) && !Visited[ny][nx] && Graph[ny][nx] == 0)
            {
                y = ny;
                x = nx;
                found = true;
                break;
            }
        }

        if (!found)
        {
            int back_d = (d + 2) % 4;
            int ny = y + dy[back_d];
            int nx = x + dx[back_d];

            if (IsRange(ny, nx) && Graph[ny][nx] == 0)
            {
                y = ny;
                x = nx;
            }
            else
            {
                break;
            }
        }
    }

    return cleaned_count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> r >> c >> d;

    vector<vector<int>> Graph(N, vector<int>(M, 0));
    vector<vector<bool>> Visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Graph[i][j];
        }
    }

    cout << Clear(Graph, Visited, r, c, d) << "\n";

    return 0;
}
