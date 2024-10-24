#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back

typedef pair<int, int> pii;

int T, W;
int dp[1001][31][3];
vector<int> Inputs;

int main() {
    FASTIO

    cin >> T >> W;
    vector<int> Inputs(T);

    FOR(i, T) {
        cin >> Inputs[i];
    }

    if (Inputs[0] == 1)
        dp[0][0][1] = 1;
    if (Inputs[0] == 2)
        dp[0][1][2] = 1;

    for (int t = 1; t < T; ++t) {
        for (int w = 0; w <= W; ++w) {
            dp[t][w][1] = dp[t - 1][w][1] + (Inputs[t] == 1);
            dp[t][w][2] = dp[t - 1][w][2] + (Inputs[t] == 2);

            if (w > 0) {
                dp[t][w][1] = max(dp[t][w][1], dp[t - 1][w - 1][2] + (Inputs[t] == 1));
                dp[t][w][2] = max(dp[t][w][2], dp[t - 1][w - 1][1] + (Inputs[t] == 2));
            }
        }
    }

    int result = 0;
    for (int w = 0; w <= W; ++w) {
        result = max(result, max(dp[T - 1][w][1], dp[T - 1][w][2]));
    }

    cout << result << endl;

    return 0;
}