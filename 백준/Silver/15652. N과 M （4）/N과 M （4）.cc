#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

vector<int> Lst;
int N, M;

vector<int> TempLst;

void BackTrack(int pos) {
    if (TempLst.size() == M) {
        FOR(i, M) {
            cout << TempLst[i] << " ";
        }
        cout << endl;

        return;
    }

    if (pos >= N) {
        return;
    }

    for (int i = pos; i < N; i++) {
        TempLst.push_back(Lst[i]);
        BackTrack(i);
        TempLst.pop_back();
    }
}

int main() {
    FASTIO

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        Lst.push_back(i);
    }

    BackTrack(0);

    return 0;
}