#include <bits/stdc++.h>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    for (const auto& puddle : puddles) {
        dp[puddle[0] - 1][puddle[1] - 1] = -1;
    }
    
    dp[0][0] = 1;
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= 1000000007;
        }
    }
    
    return dp[m - 1][n - 1];
}

