#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back

typedef pair<int, int> pii;

int N;
vector<int> Inputs;
vector<int> result;

int main() {
    FASTIO

    cin >> N;

    Inputs.resize(N, 0);
    result.resize(N);

    FOR(i, N) {
        cin >> Inputs[i];
    }

    stack<pii> s;

    FOR(i, N) {
        while (!s.empty() && s.top().first <= Inputs[i]) {
            s.pop();
        }

        if (!s.empty()) {
            result[i] = s.top().second + 1;
        } else {
            result[i] = 0;
        }

        s.push({Inputs[i], i});
    }

    FOR(i, N) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}