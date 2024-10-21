#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int N;

int main() {
    FASTIO

    cin >> N;
    vector<int> Inputs(N + 1, 0);
    vector<int> DP(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> Inputs[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            DP[i] = max(DP[i], DP[i - j] + Inputs[j]);
        }
    }

    cout << DP[N] << endl;

    return 0;
}