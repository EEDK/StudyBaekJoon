#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int N, X, K;

int main() {
    FASTIO

    cin >> N >> X >> K;
    vector<int> Pos(N + 1);

    Pos[X] = 1;

    FOR(i, K) {
        int u, v;
        cin >> u >> v;

        swap(Pos[u], Pos[v]);
    }

    FOR(i, N+1) {
        if (Pos[i] == 1) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}