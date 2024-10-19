#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int N, K;
vector<vector<int>> Tree;
vector<int> level_count;

void bfs(int root) {
    queue<pair<int, int>> q;
    q.push({root, 0});
    vector<bool> visited(N + 1, false);
    visited[root] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int level = q.front().second;
        q.pop();
        level_count[level]++;

        for (int neighbor : Tree[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, level + 1});
            }
        }
    }
}

int main() {
    FASTIO
    cin >> N >> K;
    Tree.resize(N + 1);
    level_count.resize(N + 1, 0);

    FOR(i, N-1) {
        int a, b;
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    bfs(1);

    int removed_nodes = 0;
    for (int i = 0; i < N; ++i) {
        if (level_count[i] > K) {
            removed_nodes += (level_count[i] - K);
        }
    }

    cout << N - removed_nodes << endl;

    return 0;
}