#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back

typedef pair<int, int> pii;

string S;

int main() {
    FASTIO

    cin >> S;
    int size = S.size();

    // 0을 뒤집을때

    int zeroReverse = 0;
    bool IsReversing = false;
    FOR(i, size) {
        if (S[i] == '0') {
            if (IsReversing) {
                continue;
            }
            zeroReverse++;
            IsReversing = true;
        } else {
            IsReversing = false;
        }
    }

    // 1을 뒤집을때
    int oneReverse = 0;
    IsReversing = false;
    FOR(i, size) {
        if (S[i] == '1') {
            if (IsReversing) {
                continue;
            } else {
                oneReverse++;
                IsReversing = true;
            }
        } else {
            IsReversing = false;
        }
    }

    cout << min(zeroReverse, oneReverse) << endl;

    return 0;
}