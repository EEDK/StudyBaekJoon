#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T > 0)
    {
        T--;

        int n;
        cin >> n;

        vector<vector<int>> Inputs(2, vector<int>(n, 0));
        vector<vector<int>> DP(2, vector<int>(n, 0));

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> Inputs[i][j];
            }
        }

        DP[0][0] = Inputs[0][0];
        DP[1][0] = Inputs[1][0];

        if (n > 1) {
            DP[0][1] = Inputs[0][1] + DP[1][0];
            DP[1][1] = Inputs[1][1] + DP[0][0];
        }

        for (int i = 2; i < n; i++) {
            DP[0][i] = max(DP[1][i-1], DP[1][i-2]) + Inputs[0][i];
            DP[1][i] = max(DP[0][i-1], DP[0][i-2]) + Inputs[1][i];
        }

        cout << max(DP[0][n-1], DP[1][n-1]) << "\n";
    }

    return 0;
}
