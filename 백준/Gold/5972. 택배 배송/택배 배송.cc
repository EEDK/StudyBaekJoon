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

int main() {
    FASTIO
    cin >> N >> M;

    Graph.resize(N + 1);
    vector<int> Routes(N + 1, INF);
    vector<bool> processed(N + 1, false);

    FOR(i, M) {
        int A, B, C;

        cin >> A >> B >> C;

        Graph[A].PB({B, C});
        Graph[B].PB({A, C});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, 1});
    Routes[1] = 0;

    while (!pq.empty()) {
        int CurrentCost = pq.top().first;
        int CurrentNode = pq.top().second;
        pq.pop();

        if (processed[CurrentNode])
            continue;
        processed[CurrentNode] = true;

        for (auto& edge : Graph[CurrentNode]) {
            int nextNode = edge.first;
            int nextCost = edge.second;

            if (Routes[nextNode] > CurrentCost + nextCost) {
                Routes[nextNode] = CurrentCost + nextCost;
                pq.push({Routes[nextNode], nextNode});
            }
        }

    }

    cout << Routes[N] << endl;

    return 0;
}