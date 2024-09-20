#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

void Drop(vector<vector<char>>& Maps)
{
    for (int j = 0; j < 6; j++)
    {
        int emptyRow = 11;
        for (int i = 11; i >= 0; i--)
        {
            if (Maps[i][j] != '.')
            {
                if (i != emptyRow)
                {
                    Maps[emptyRow][j] = Maps[i][j];
                    Maps[i][j] = '.';
                }
                emptyRow--;
            }
        }
    }
}

void DFS(vector<vector<char>>& Maps, vector<vector<bool>>& Visited, int x, int y, char Color, vector<pair<int, int>>& connectedPuyos)
{
    Visited[x][y] = true;
    connectedPuyos.push_back({x, y});

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
        if (Visited[nx][ny] || Maps[nx][ny] != Color) continue;

        DFS(Maps, Visited, nx, ny, Color, connectedPuyos);
    }
}


int main()
{
    vector<vector<char>> Maps(12, vector<char>(6, 0));

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> Maps[i][j];
        }
    }

    int chainCount = 0;

    while (true)
    {
        bool exploded = false;
        vector<vector<bool>> Visited(12, vector<bool>(6, false));

        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (Maps[i][j] != '.' && !Visited[i][j])
                {
                    vector<pair<int, int>> connectedPuyos;
                    DFS(Maps, Visited, i, j, Maps[i][j], connectedPuyos);

                    if (connectedPuyos.size() >= 4)
                    {
                        exploded = true;
                        for (auto& puyo : connectedPuyos)
                        {
                            Maps[puyo.first][puyo.second] = '.';
                        }
                    }
                }
            }
        }

        if (!exploded) break;

        Drop(Maps);

        chainCount++;
    }

    cout << chainCount << endl;

    return 0;
}
