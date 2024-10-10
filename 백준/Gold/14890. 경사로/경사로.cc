#include <bits/stdc++.h>

using namespace std;

int N, L;
int answer = 0;

bool canPass(vector<int>& road) {
    vector<bool> slope(N, false);

    for (int i = 0; i < N - 1; i++) {
        if (road[i] == road[i + 1]) {
            continue;
        } else if (road[i] + 1 == road[i + 1]) {
            if (i - L + 1 < 0) return false;
            for (int j = 0; j < L; j++) {
                if (road[i - j] != road[i] || slope[i - j]) return false;
            }
            for (int j = 0; j < L; j++) {
                slope[i - j] = true;
            }
        } else if (road[i] - 1 == road[i + 1]) {
            if (i + L >= N) return false;
            for (int j = 1; j < L + 1; j++) {
                if (road[i + j] != road[i + 1] || slope[i + j]) return false;
            }
            for (int j = 1; j < L + 1; j++) {
                slope[i + j] = true;
            }
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;
    vector<vector<int>> Graph(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Graph[i][j];
        }
    }

    // 행 검사 →
    for (int i = 0; i < N; i++) {
        vector<int> row(N);
        for (int j = 0; j < N; j++) {
            row[j] = Graph[i][j];
        }
        if (canPass(row)) answer++;
    }

    // 열 검사 ↓
    for (int i = 0; i < N; i++) {
        vector<int> col(N);
        for (int j = 0; j < N; j++) {
            col[j] = Graph[j][i];
        }
        if (canPass(col)) answer++;
    }

    cout << answer << "\n";

    return 0;
}
