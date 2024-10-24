#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back

typedef pair<int, int> pii;

int main() {
    FASTIO

    int N;
    cin >> N;

    unordered_map<string, int> Maps;

    FOR(i, N) {
        int s;
        int t;
        cin >> s >> t;
        vector<string> Tags(t);
        FOR(j, t) {
            cin >> Tags[j];

            Maps[Tags[j]] += 1;
        }
    }

    string answer = "";
    int Cnt = 0;
    for (const auto& item : Maps) {
        if (item.second > Cnt) {
            Cnt = item.second;
            answer = item.first;
        }
    }

    int Test = 0;
    for (const auto& item : Maps) {
        if (item.second == Cnt) {
            Test++;
        }
    }

    if (Test > 1) {
        cout << -1 << endl;
    } else {
        cout << answer << endl;
    }

    return 0;
}