#include <bits/stdc++.h>
using namespace std;

int N;
const int MOD = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<vector<int>> Inputs(N, vector<int>(N, 0));
    vector<vector<vector<int>>> DP(N, vector<vector<int>>(N, vector<int>(3, 0)));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Inputs[i][j];
        }
    }

    DP[0][1][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (Inputs[i][j] == 1) continue;

            if (j > 0 && Inputs[i][j] == 0) {
                DP[i][j][0] += DP[i][j - 1][0];
                if (i > 0) DP[i][j][0] += DP[i][j - 1][2];
            }

            if (i > 0 && Inputs[i][j] == 0) {
                DP[i][j][1] += DP[i - 1][j][1];
                if (j > 0) DP[i][j][1] += DP[i - 1][j][2];
            }

            if (i > 0 && j > 0 && Inputs[i][j] == 0 && Inputs[i - 1][j] == 0 && Inputs[i][j - 1] == 0) {
                DP[i][j][2] += DP[i - 1][j - 1][0];
                DP[i][j][2] += DP[i - 1][j - 1][1];
                DP[i][j][2] += DP[i - 1][j - 1][2];
            }
        }
    }

    cout << DP[N - 1][N - 1][0] + DP[N - 1][N - 1][1] + DP[N - 1][N - 1][2] << "\n";

    return 0;
}
