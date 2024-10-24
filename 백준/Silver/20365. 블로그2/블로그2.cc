#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back

typedef pair<int, int> pii;

int N;

string S;

int main() {
    FASTIO

    cin >> N >> S;

    int RedCnt = 0;
    int BlueCnt = 0;

    bool PrevBlue = false;
    bool PrevRed = false;

    FOR(i, N) {
        if (S[i] == 'B') {
            if (PrevBlue)
                continue;
            else {
                BlueCnt++;
                PrevBlue = true;
                PrevRed = false;
            }
        } else if (S[i] == 'R') {
            if (PrevRed)
                continue;
            else {
                RedCnt++;
                PrevBlue = false;
                PrevRed = true;
            }
        }
    }

    cout << min(RedCnt, BlueCnt) + 1 << endl;

    return 0;
}