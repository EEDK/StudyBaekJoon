#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    long u, v, weight;
};

void initialize_single_source(int V, vector<long>& dist, vector<long>& pred, int source)
{
    dist.resize(V + 1, INT_MAX);
    pred.resize(V + 1, -1);
    dist[source] = 0;
}

void relax(int u, int v, int weight, vector<long>& dist, vector<long>& pred)
{
    if (dist[u] != INT_MAX && dist[v] > dist[u] + weight)
    {
        dist[v] = dist[u] + weight;
        pred[v] = u;
    }
}

bool bellman_ford(int V, vector<Edge>& Edges, int source, vector<long>& dist, vector<long>& pred)
{
    initialize_single_source(V, dist, pred, source);

    for (int i = 1; i <= V - 1; i++)
    {
        for (auto& edge : Edges)
        {
            relax(edge.u, edge.v, edge.weight, dist, pred);
        }
    }

    for (auto& edge : Edges)
    {
        if (dist[edge.u] != INT_MAX && dist[edge.v] > dist[edge.u] + edge.weight)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<Edge> Edges(E);

    for (int i = 0; i < E; i++)
    {
        cin >> Edges[i].u >> Edges[i].v >> Edges[i].weight;
    }

    vector<long> dist;
    vector<long> pred;

    if (bellman_ford(V, Edges, 1, dist, pred))
    {
        for (int i = 2; i <= V; i++)
        {
            if (dist[i] != INT_MAX)
            {
                cout << dist[i] << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
