#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;

int T;

ll Solve(vector<int>& Inputs) {
    int n = Inputs.size();
    ll maxProfit = 0;
    int maxPrice = 0;

    for (int i = n - 1; i >= 0; --i) {
        if (Inputs[i] > maxPrice) {
            maxPrice = Inputs[i];
        }
        maxProfit += maxPrice - Inputs[i];
    }

    return maxProfit;
}

int main() {
    FASTIO
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> Inputs(N);
        FOR(i, N) {
            cin >> Inputs[i];
        }

        cout << Solve(Inputs) << endl;
    }

    return 0;
}
