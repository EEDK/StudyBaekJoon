#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int N;
vector<vector<int>> Graph;

int main() {
    FASTIO

    cin >> N;
    Graph.resize(N, vector<int>(N, 0));

    FOR(i, N) {
        FOR(j, N) {
            cin >> Graph[i][j];
        }
    }

    FOR(k, N) {
        FOR(i, N) {
            FOR(j, N) {
                if (Graph[i][k] && Graph[k][j]) {
                    Graph[i][j] = 1;
                }
            }
        }
    }

    FOR(i, N) {
        FOR(j, N) {
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
