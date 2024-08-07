#include <bits/stdc++.h>

using namespace std;

int binomial_coefficient(int N, int K) {
    vector<vector<int>> DP(N + 1, vector<int>(N + 1, 0));

    for (int i = 0; i <= N; i++) {
        DP[i][1] = i;
        DP[i][0] = 1;
        DP[i][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            DP[i][j] = DP[i - 1][j] + DP[i - 1][j - 1];
        }
    }

    return DP[N][K];
}

int main() {
    int N, K;

    cin >> N >> K;

    cout << binomial_coefficient(N, K) << endl;

    return 0;
}
