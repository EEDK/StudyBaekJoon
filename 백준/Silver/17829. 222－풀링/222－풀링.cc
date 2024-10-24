#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back

typedef pair<int, int> pii;

int N;
vector<vector<int>> Inputs;

int pooling(const vector<vector<int>>& matrix, int x, int y) {
    vector<int> values = {
        matrix[x][y], matrix[x + 1][y],
        matrix[x][y + 1], matrix[x + 1][y + 1]
    };
    sort(values.begin(), values.end());
    return values[2];
}

int solvePooling(vector<vector<int>>& matrix, int size, int x, int y) {
    if (size == 2) {
        return pooling(matrix, x, y);
    }

    int half = size / 2;
    vector<int> results = {
        solvePooling(matrix, half, x, y),
        solvePooling(matrix, half, x, y + half),
        solvePooling(matrix, half, x + half, y),
        solvePooling(matrix, half, x + half, y + half)
    };

    sort(results.begin(), results.end());
    return results[2];
}


int main() {
    FASTIO
    cin >> N;

    Inputs.resize(N, vector<int>(N, 0));

    FOR(i, N) {
        FOR(j, N) {
            cin >> Inputs[i][j];
        }
    }

    cout << solvePooling(Inputs, N, 0, 0) << endl;

    return 0;
}