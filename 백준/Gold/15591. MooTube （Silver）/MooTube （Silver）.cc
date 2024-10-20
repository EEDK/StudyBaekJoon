#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int N, Q;
vector<vector<pii>> graph;

int bfs(int start, int k) {
    vector<bool> visited(N + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int count = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        count++;

        for (auto& edge : graph[cur]) {
            int next = edge.first;
            int usado = edge.second;

            if (!visited[next] && usado >= k) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return count - 1;
}

int main() {
    FASTIO

    cin >> N >> Q;
    graph.resize(N + 1);

    FOR(i, N - 1) {
        int p, q, r;
        cin >> p >> q >> r;
        graph[p].push_back({q, r});
        graph[q].push_back({p, r});
    }

    FOR(i, Q) {
        int k, v;
        cin >> k >> v;
        cout << bfs(v, k) << endl;
    }

    return 0;
}