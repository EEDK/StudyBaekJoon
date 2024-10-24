#include <bits/stdc++.h>

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back

using namespace std;
typedef pair<int, int> pii;

int N;

vector<int> TempLst;
int BackTrackResult;

void BackTrack(int pos, vector<int> Inputs) {
    if (TempLst.size() >= 3) {
        int result = accumulate(TempLst.begin(), TempLst.end(), 0) % 10;

        if (result > BackTrackResult) {
            BackTrackResult = result;
        }

        return;
    }

    if (pos >= Inputs.size()) {
        return;
    }

    TempLst.push_back(Inputs[pos]);
    BackTrack(pos + 1, Inputs);
    TempLst.pop_back();
    BackTrack(pos + 1, Inputs);
}

int Solve(vector<int> Inputs) {
    BackTrackResult = 0;

    BackTrack(0, Inputs);
    return BackTrackResult;
}

int main() {
    FASTIO

    cin >> N;

    int MaxNum = 0;
    int answer = 1;

    FOR(i, N) {
        vector<int> Inputs(5, 0);
        FOR(j, 5) {
            cin >> Inputs[j];
        }

        int nowNum = Solve(Inputs);
        if (nowNum >= MaxNum) {
            answer = i + 1;
            MaxNum = nowNum;
        }
    }

    cout << answer << endl;

    return 0;
}