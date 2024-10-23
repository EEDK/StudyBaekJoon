#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int Graph[101][101] = {0};

int main() {
    FASTIO
    for (int i = 0; i < 4; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; ++x) {
            for (int y = y1; y < y2; ++y) {
                Graph[x][y] = 1;
            }
        }
    }

    int area = 0;
    FOR(i, 101) {
        FOR(j, 101) {
            if (Graph[i][j] == 1) {
                area++;
            }
        }
    }

    cout << area << endl;

    return 0;
}