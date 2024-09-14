#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> DP(N, vector<int>(N, 0));

    vector<vector<int>> triangle(N);

    for (int i = 0; i < N; i++)
    {
        triangle[i].resize(i + 1);
        for (int j = 0; j < i + 1; j++)
        {
            cin >> triangle[i][j];
        }
    }
    DP[0][0] = triangle[0][0];

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0)
            {
                DP[i][j] = DP[i - 1][j] + triangle[i][j];
            }

            else if (j == i)
            {
                DP[i][j] = DP[i - 1][j - 1] + triangle[i][j];
            }

            else
            {
                DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + triangle[i][j];
            }
        }
    }

    cout << *max_element(DP[N - 1].begin(), DP[N - 1].end()) << "\n";

    return 0;
}
