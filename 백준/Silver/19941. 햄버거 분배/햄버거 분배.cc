#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int N, K;
string Inputs;

int main() {
    FASTIO

    cin >> N >> K >> Inputs;

    int answer = 0;
    FOR(i, N) {
        if (Inputs[i] == 'P') {
            for (int j = i - K; j <= i + K; j++) {
                if (j >= N) {
                    break;
                }
                if (Inputs[j] == 'H') {
                    Inputs[j] = 'N';
                    answer++;
                    break;
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}