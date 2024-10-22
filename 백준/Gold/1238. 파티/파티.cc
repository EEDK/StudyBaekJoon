#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

struct Edge {
    int v, weight;
};

int N, M, X;
vector<vector<Edge>> Graph;
vector<int> distToX, distFromX;

vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curDist > dist[curNode])
            continue;

        for (const auto& edge : Graph[curNode]) {
            int nextNode = edge.v;
            int nextDist = curDist + edge.weight;

            if (nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }

    return dist;
}

int main() {
    FASTIO

    cin >> N >> M >> X;
    Graph.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Graph[u].push_back({v, w});
    }

    distToX = dijkstra(X);

    vector<vector<Edge>> reverseGraph(N + 1);
    for (int u = 1; u <= N; ++u) {
        for (const auto& edge : Graph[u]) {
            reverseGraph[edge.v].push_back({u, edge.weight});
        }
    }
    swap(Graph, reverseGraph);
    distFromX = dijkstra(X);

    int maxTime = 0;
    for (int i = 1; i <= N; ++i) {
        if (i != X) {
            maxTime = max(maxTime, distToX[i] + distFromX[i]);
        }
    }

    cout << maxTime << endl;

    return 0;
}