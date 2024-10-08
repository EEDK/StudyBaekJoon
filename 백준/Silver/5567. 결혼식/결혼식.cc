#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> Graph;
vector<bool> Visited;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    Graph.resize(n);
    Visited.resize(n, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        Graph[u - 1].push_back(v - 1);
        Graph[v - 1].push_back(u - 1);
    }

    queue<int> q;
    q.push(0);
    Visited[0] = true;

    int inviteCount = 0;
    vector<int> dist(n, -1);
    dist[0] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (const auto& next : Graph[cur])
        {
            if (!Visited[next])
            {
                Visited[next] = true;
                dist[next] = dist[cur] + 1;
                if (dist[next] <= 2)
                {
                    inviteCount++;
                    q.push(next);
                }
            }
        }
    }

    cout << inviteCount << "\n";

    return 0;
}
