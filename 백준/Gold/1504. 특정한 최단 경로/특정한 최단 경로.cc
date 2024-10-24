#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back

using namespace std;
typedef pair<int, int> pii;

int N, M;
vector<vector<pii>> Graph;

vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int CurrentCost = pq.top().first;
        int CurrentNode = pq.top().second;
        pq.pop();

        if (CurrentCost > dist[CurrentNode])
            continue;

        for (const auto& Edge : Graph[CurrentNode]) {
            int adjNode = Edge.first;
            int adjCost = Edge.second;

            if (dist[adjNode] > CurrentCost + adjCost) {
                dist[adjNode] = CurrentCost + adjCost;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {
    FASTIO
    cin >> N >> M;

    Graph.resize(N + 1);

    FOR(i, M) {
        int A, B, C;
        cin >> A >> B >> C;
        Graph[A].PB({B, C});
        Graph[B].PB({A, C});
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> dist_from_1 = dijkstra(1);

    vector<int> dist_from_v1 = dijkstra(v1);

    vector<int> dist_from_v2 = dijkstra(v2);

    int route1 = dist_from_1[v1] + dist_from_v1[v2] + dist_from_v2[N];
    int route2 = dist_from_1[v2] + dist_from_v2[v1] + dist_from_v1[N];

    int result = min(route1, route2);

    if (result >= INF || dist_from_1[v1] == INF || dist_from_1[v2] == INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
