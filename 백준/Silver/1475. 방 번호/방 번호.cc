#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

string n;

int main() {
    FASTIO

    cin >> n;

    unordered_map<char, int> Map;

    int answer = 0;
    FOR(i, n.size()) {
        Map[n[i]] += 1;
    }

    int SixAndNine = Map['6'] + Map['9'];
    if ((SixAndNine + 1) / 2 > answer) {
        answer = (SixAndNine + 1) / 2;
    }

    for (char c = '0'; c <= '9'; ++c) {
        if (c != '6' && c != '9') {
            answer = max(answer, Map[c]);
        }
    }

    cout << answer << endl;

    return 0;
}