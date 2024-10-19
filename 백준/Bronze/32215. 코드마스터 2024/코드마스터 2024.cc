#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int n, m, k;

int main() {
    FASTIO
    cin >> n >> m >> k;

    cout << k * m + m << endl;

    return 0;
}