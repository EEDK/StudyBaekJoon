#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;

ll N;

int main() {
    FASTIO

    cin >> N;

    if (N > 0) {
        if (N <= SHRT_MAX) {
            cout << "short" << endl;
        } else if (N <= INT_MAX) {
            cout << "int" << endl;
        } else {
            cout << "long long" << endl;
        }
    } else {
        if (N >= SHRT_MIN) {
            cout << "short" << endl;
        } else if (N >= INT_MIN) {
            cout << "int" << endl;
        } else {
            cout << "long long" << endl;
        }
    }

    return 0;
}