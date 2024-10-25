#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back

typedef pair<int, int> pii;

vector<vector<int>> office;
vector<pair<int, pii>> cctv;
int N, M, answer = INF;

vector<vector<int>> directions = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

void monitor(vector<vector<int>>& temp, int x, int y, int dir) {
    int nx = x, ny = y;
    while (true) {
        nx += directions[dir][0];
        ny += directions[dir][1];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M || temp[nx][ny] == 6)
            break;
        if (temp[nx][ny] == 0)
            temp[nx][ny] = -1;
    }
}

void simulate(int idx, vector<vector<int>> temp) {
    if (idx == cctv.size()) {
        int blind_spot = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (temp[i][j] == 0)
                    ++blind_spot;
            }
        }
        answer = min(answer, blind_spot);
        return;
    }

    int type = cctv[idx].first;
    int x = cctv[idx].second.first;
    int y = cctv[idx].second.second;

    if (type == 1) {
        for (int i = 0; i < 4; ++i) {
            vector<vector<int>> new_temp = temp;
            monitor(new_temp, x, y, i);
            simulate(idx + 1, new_temp);
        }
    } else if (type == 2) {
        for (int i = 0; i < 2; ++i) {
            vector<vector<int>> new_temp = temp;
            monitor(new_temp, x, y, i);
            monitor(new_temp, x, y, i + 2);
            simulate(idx + 1, new_temp);
        }
    } else if (type == 3) {
        for (int i = 0; i < 4; ++i) {
            vector<vector<int>> new_temp = temp;
            monitor(new_temp, x, y, i);
            monitor(new_temp, x, y, (i + 1) % 4);
            simulate(idx + 1, new_temp);
        }
    } else if (type == 4) {
        for (int i = 0; i < 4; ++i) {
            vector<vector<int>> new_temp = temp;
            monitor(new_temp, x, y, i);
            monitor(new_temp, x, y, (i + 1) % 4);
            monitor(new_temp, x, y, (i + 2) % 4);
            simulate(idx + 1, new_temp);
        }
    } else if (type == 5) {
        vector<vector<int>> new_temp = temp;
        for (int i = 0; i < 4; ++i) {
            monitor(new_temp, x, y, i);
        }
        simulate(idx + 1, new_temp);
    }
}

int main() {
    FASTIO;
    cin >> N >> M;
    office.resize(N, vector<int>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> office[i][j];
            if (office[i][j] >= 1 && office[i][j] <= 5) {
                cctv.push_back({office[i][j], {i, j}});
            }
        }
    }

    simulate(0, office);
    cout << answer << endl;
    return 0;
}