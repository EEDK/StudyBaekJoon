#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF (~0U >> 2)
#define PB push_back
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int N, M;

vvi Graph;
vector<bool> Visited;

int BFS(int Pos)
{
    int result = 0;

    Visited[Pos] = true;
    queue<int> Queue;
    Queue.push(Pos);

    while (!Queue.empty())
    {
        int node = Queue.front();
        Queue.pop();
        for (const auto& adj : Graph[node])
        {
            if (!Visited[adj])
            {
                result = result + 1;
                Visited[adj] = true;
                Queue.push(adj);
            }
        }
    }


    return result;
}

int main()
{
    FASTIO

    cin >> N >> M;
    Graph.resize(N + 1);
    Visited.resize(N + 1, false);

    FOR(i, M)
    {
        int u, v;
        cin >> u >> v;

        Graph[u].PB(v);
        Graph[v].PB(u);
    }

    cout << BFS(1) << endl;

    return 0;
}
