#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;

int N;
vector<vector<int>> Graph;
vector<vector<ll>> DP;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    Graph.resize(N, vector<int>(N, 0));
    DP.resize(N, vector<ll>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Graph[i][j];
        }
    }

    DP[0][0] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (DP[i][j] == 0 || Graph[i][j] == 0) continue;

            int JumpPos = Graph[i][j];

            if (j + JumpPos < N)
            {
                DP[i][j + JumpPos] += DP[i][j];
            }

            if (i + JumpPos < N)
            {
                DP[i + JumpPos][j] += DP[i][j];
            }
        }
    }

    cout << DP[N - 1][N - 1] << endl;

    return 0;
}
