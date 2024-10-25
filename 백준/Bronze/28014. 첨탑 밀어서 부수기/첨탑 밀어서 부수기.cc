#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back

typedef pair<int, int> pii;
typedef vector<int> vi;

int N;
vi Inputs;

int main() {
    FASTIO;

    cin >> N;
    Inputs.resize(N, 0);

    FOR(i, N) {
        cin >> Inputs[i];
    }

    int answer = 1;
    FOR(i, N-1) {
        if (Inputs[i] <= Inputs[i + 1]) {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}