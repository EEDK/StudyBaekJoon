#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;

    cin >> N >> Q;

    int S[100001] = {};

    for (int i = 1; i <= N; ++i) {
        int input;
        cin >> input;
        S[i] = S[i - 1] + input;
    }

    for (int i = 0; i < Q; ++i) {
        int StartPos, EndPos;

        cin >> StartPos >> EndPos;
        cout << S[EndPos] - S[StartPos - 1] << "\n";
    }

    return 0;
}
