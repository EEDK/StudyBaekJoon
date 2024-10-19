#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int N;
string S;

int main() {
    FASTIO

    cin >> N >> S;

    unordered_map<string, int> Maps;

    FOR(i, N) {
        string UserName, Answer;
        cin >> UserName >> Answer;

        if (UserName == S) {
            cout << Maps[Answer] << endl;
            break;
        } else {
            Maps[Answer]++;
        }
    }

    return 0;
}