#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Edge;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    vector<vector<Edge>> Graph;
    Graph.resize(V + 1);

    vector<int> Distance;
    Distance.resize(V + 1);
    fill(Distance.begin(), Distance.end(), INT_MAX);
    
    for (int i = 0; i < E; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;
        Graph[u].push_back({v, w});
    }

    int start, end;

    cin >> start >> end;

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    Distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int a = pq.top().second;
        int NowDistance = pq.top().first;

        pq.pop();

        if (NowDistance > Distance[a]) continue;

        for (auto adj : Graph[a])
        {
            int b = adj.first;
            int w = adj.second;

            if (Distance[a] + w < Distance[b])
            {
                Distance[b] = Distance[a] + w;

                pq.push({Distance[b], b});
            }
        }
    }

    cout << Distance[end] << "\n";

    return 0;
}
