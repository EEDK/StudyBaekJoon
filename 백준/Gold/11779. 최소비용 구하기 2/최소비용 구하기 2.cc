#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back
typedef pair<int, int> pii;

int N, M;

vector<vector<pii>> Graph;
vector<int> dist;

vector<int> Dijkstra(int start, int end) {
    vector<int> parent(N + 1, -1);
    vector<bool> processor(N + 1, false);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int CurrentCost = pq.top().first;
        int CurrentNode = pq.top().second;
        pq.pop();

        if (processor[CurrentNode])
            continue;

        processor[CurrentNode] = true;

        for (const auto& item : Graph[CurrentNode]) {
            int AdjNode = item.first;
            int AdjCost = item.second;

            if (dist[AdjNode] > AdjCost + CurrentCost) {
                dist[AdjNode] = AdjCost + CurrentCost;
                parent[AdjNode] = CurrentNode;
                pq.push({dist[AdjNode], AdjNode});
            }
        }
    }

    vector<int> path;
    for (int node = end; node != -1; node = parent[node]) {
        path.push_back(node);
    }
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    FASTIO

    cin >> N >> M;

    Graph.resize(N + 1);
    dist.resize(N + 1, INF);

    FOR(i, M) {
        int u, v, w;
        cin >> u >> v >> w;
        Graph[u].push_back({v, w});
    }

    int start, end;
    cin >> start >> end;

    vector<int> path = Dijkstra(start, end);

    cout << dist[end] << endl;

    cout << path.size() << endl;

    FOR(i, path.size()) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}