#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<int> T(N + 1, 0);
    vector<int> P(N + 1, 0);
    vector<int> DP(N + 2, 0);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i > 0; i--) {
        if (i + T[i] > N + 1) {
            DP[i] = DP[i + 1];
        } else {
            DP[i] = max(DP[i + 1], P[i] + DP[i + T[i]]);
        }
    }

    cout << DP[1] << endl;

    return 0;
}
