#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

typedef long long ll;

int N, M;
vector<vector<int>> Map;
vector<vector<vector<int>>> DP;

int main()
{
    FASTIO;

    cin >> N >> M;
    Map.resize(N, vector<int>(M, 0));
    DP.resize(N, vector<vector<int>>(M, vector<int>(3, INT_MAX)));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Map[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        DP[0][i][0] = Map[0][i];
        DP[0][i][1] = Map[0][i];
        DP[0][i][2] = Map[0][i];
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (j > 0) 
                DP[i][j][0] = Map[i][j] + min(DP[i - 1][j - 1][1], DP[i - 1][j - 1][2]);

            if (j < M - 1)
                DP[i][j][1] = Map[i][j] + min(DP[i - 1][j + 1][0], DP[i - 1][j + 1][2]);

            DP[i][j][2] = Map[i][j] + min(DP[i - 1][j][0], DP[i - 1][j][1]);
        }
    }

    int result = INT_MAX;
    for (int i = 0; i < M; i++)
    {
        result = min({result, DP[N - 1][i][0], DP[N - 1][i][1], DP[N - 1][i][2]});
    }

    cout << result << endl;

    return 0;
}
