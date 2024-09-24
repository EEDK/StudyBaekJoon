#include <bits/stdc++.h>

using namespace std;

int R, C;
char lake[1500][1500];
bool visited[1500][1500];
queue<pair<int, int>> swans, water, nextSwans, nextWater;
pair<int, int> swan1, swan2;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool bfs()
{
    while (!swans.empty())
    {
        auto [x, y] = swans.front();
        swans.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny]) continue;
            visited[nx][ny] = true;

            if (nx == swan2.first && ny == swan2.second) return true;

            if (lake[nx][ny] == '.')
            {
                swans.push({nx, ny});
            }
            else
            {
                nextSwans.push({nx, ny});
            }
        }
    }
    return false;
}

void meltIce()
{
    while (!water.empty())
    {
        auto [x, y] = water.front();
        water.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C || lake[nx][ny] != 'X') continue;

            lake[nx][ny] = '.';
            nextWater.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin.tie(NULL);

    cin >> R >> C;
    bool found = false;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> lake[i][j];
            if (lake[i][j] == 'L')
            {
                if (!found)
                {
                    swan1 = {i, j};
                    swans.push(swan1);
                    visited[i][j] = true;
                    found = true;
                }
                else
                {
                    swan2 = {i, j};
                }
                lake[i][j] = '.';
            }

            if (lake[i][j] == '.')
            {
                water.push({i, j});
            }
        }
    }

    int days = 0;
    while (true)
    {
        if (bfs())
        {
            cout << days << '\n';
            break;
        }

        meltIce();

        swans = nextSwans;
        water = nextWater;

        nextSwans = queue<pair<int, int>>();
        nextWater = queue<pair<int, int>>();

        days++;
    }

    return 0;
}
