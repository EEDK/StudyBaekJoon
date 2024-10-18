#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int M, N;
vector<vector<int>> Inputs;
vector<vector<int>> DP;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y)
{
    if (DP[x][y] != -1) return DP[x][y];

    if (x == M - 1 && y == N - 1) return 1;

    DP[x][y] = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N && Inputs[nx][ny] < Inputs[x][y])
        {
            DP[x][y] += dfs(nx, ny);
        }
    }

    return DP[x][y];
}

int main()
{
    FASTIO
    cin >> M >> N;

    Inputs.resize(M, vector<int>(N));
    DP.resize(M, vector<int>(N, -1));

    FOR(i, M)
    {
        FOR(j, N)
        {
            cin >> Inputs[i][j];
        }
    }

    cout << dfs(0, 0) << endl;

    return 0;
}
