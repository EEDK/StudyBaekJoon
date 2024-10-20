#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int N;
vector<vector<int>> Graph, ReverseGraph;

void DFS(int pos, vector<bool>& Visited, const vector<vector<int>>& G) {
    Visited[pos] = true;
    for (const auto& Edge : G[pos]) {
        if (!Visited[Edge]) {
            DFS(Edge, Visited, G);
        }
    }
}

int main() {
    FASTIO

    cin >> N;
    Graph.resize(N + 1);
    ReverseGraph.resize(N + 1);

    FOR(i, N - 1) {
        int a, b;
        cin >> a >> b;
        Graph[a].push_back(b);
        ReverseGraph[b].push_back(a);
    }

    int result = -1;

    for (int i = 1; i <= N; i++) {
        vector<bool> Visited(N + 1, false);
        DFS(i, Visited, ReverseGraph);

        bool allVisited = true;
        for (int j = 1; j <= N; j++) {
            if (!Visited[j]) {
                allVisited = false;
                break;
            }
        }

        if (allVisited) {
            result = i;
            break;
        }
    }

    cout << result << endl;

    return 0;
}