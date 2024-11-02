#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF (~0U >> 2)
#define PB push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N;
vector<vi> Graph;
vector<vi> DP;
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;
    DP[node][0] = 0;
    DP[node][1] = 1;

    for (int child : Graph[node])
    {
        if (!visited[child])
        {
            dfs(child);
            DP[node][0] += DP[child][1];
            DP[node][1] += min(DP[child][0], DP[child][1]);
        }
    }
}

int main()
{
    FASTIO;

    cin >> N;
    Graph.resize(N + 1);
    DP.resize(N + 1, vector<int>(2));
    visited.resize(N + 1, false);

    FOR(i, N - 1)
    {
        int u, v;
        cin >> u >> v;

        Graph[u].PB(v);
        Graph[v].PB(u);
    }

    dfs(1);

    cout << min(DP[1][0], DP[1][1]) << endl;

    return 0;
}
