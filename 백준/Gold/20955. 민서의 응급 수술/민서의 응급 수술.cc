#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int N, M;
vector<vector<int>> Graph;
vector<int> parent;
vector<int> rank_arr;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (rank_arr[rootX] > rank_arr[rootY]) {
            parent[rootY] = rootX;
        } else if (rank_arr[rootX] < rank_arr[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank_arr[rootX]++;
        }
        return true;
    }
    return false;
}

int main() {
    FASTIO

    cin >> N >> M;

    Graph.resize(N + 1);
    parent.resize(N + 1);
    rank_arr.resize(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }

    int extra_edges = 0;

    FOR(i, M) {
        int u, v;
        cin >> u >> v;

        if (!union_sets(u, v)) {
            extra_edges++;
        }
    }

    int components = 0;
    for (int i = 1; i <= N; ++i) {
        if (find(i) == i) {
            components++;
        }
    }

    cout << extra_edges + (components - 1) << endl;

    return 0;
}