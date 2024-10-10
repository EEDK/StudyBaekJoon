#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<ll>> dp(101, vector<ll>(10, 0));
    dp.resize(101);

    for (int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= 100; i++)
    {
        dp[i][0] = dp[i - 1][1] % 1000000000;
        for (int j = 1; j < 9; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
        dp[i][9] = dp[i - 1][8] % 1000000000;
    }

    ll result = 0;
    for (int i = 0; i <= 9; i++)
    {
        result = (result + dp[N][i]) % 1000000000;
    }

    cout << result << "\n";
    return 0;
}
