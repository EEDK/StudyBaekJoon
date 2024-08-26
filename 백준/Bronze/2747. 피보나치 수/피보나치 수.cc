#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long> dp(46, 0);

    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= N + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[N] << endl;

    return 0;
}
