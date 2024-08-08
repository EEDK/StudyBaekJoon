#include <bits/stdc++.h>

using namespace std;

// dp[a][b] = dp[a-1][b] + dp[a-1][b-1]

static int Dp[31][31];

int main() {
    for (int i = 0; i <= 30; i++) {
        Dp[i][1] = i;
        Dp[i][0] = 1;
        Dp[i][i] = 1;
    }

    for (int i = 2; i <= 30; i++) {
        for (int j = 1; j < i; j++) {
            Dp[i][j] = Dp[i - 1][j] + Dp[i - 1][j - 1];
        }
    }

    int TestCase;

    cin >> TestCase;

    for (int i = 0; i < TestCase; i++) {
        int k, n;

        cin >> k >> n;

        cout << Dp[n][k] << endl;
    }

    return 0;
}
