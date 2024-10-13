#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int N;
vector<vector<int>> S;
vector<bool> selected;
int answer = INT_MAX;

void backtrack(int idx, int cnt) {
    if (cnt == N / 2) {
        int startTeam = 0, linkTeam = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (selected[i] && selected[j]) {
                    startTeam += S[i][j] + S[j][i];
                } else if (!selected[i] && !selected[j]) {
                    linkTeam += S[i][j] + S[j][i];
                }
            }
        }
        answer = min(answer, abs(startTeam - linkTeam));
        return;
    }

    for (int i = idx; i < N; i++) {
        if (!selected[i]) {
            selected[i] = true;
            backtrack(i + 1, cnt + 1);
            selected[i] = false;
        }
    }
}

int main()
{
    FASTIO;

    cin >> N;
    S.resize(N, vector<int>(N, 0));
    selected.resize(N, false);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    backtrack(0, 0);

    cout << answer << endl;

    return 0;
}
