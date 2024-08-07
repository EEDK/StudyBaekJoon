#include <bits/stdc++.h>

using namespace std;

// DP[a][b] = dp[a][b-1] + dp[a-1][b]

static int Dp[15][15];

int Solution(int a, int b) {
    for (int i = 0; i < 15; i++) {
        Dp[i][1] = 1;
        Dp[0][i] = i;
    }

    for (int i = 1; i < 15; i++) {
        for (int j = 2; j < 15; j++) {
            Dp[i][j] = Dp[i][j - 1] + Dp[i - 1][j];
        }
    }

    return Dp[a][b];
}

int main() {
    int TestCase;

    cin >> TestCase;

    for (int i = 0; i < TestCase; i++) {
        int k, n;
        
        cin >> k >> n;

        cout << Solution(k, n) << endl;
    }

    return 0;
}
