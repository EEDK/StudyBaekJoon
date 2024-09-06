#include <bits/stdc++.h>

using namespace std;

int BFS(const vector<vector<int>>& Graph, vector<bool>& visited, int start, int target)
{
    queue<pair<int, int>> Queue;
    Queue.push({start, 0});

    visited[start] = true;

    while (!Queue.empty())
    {
        int x = Queue.front().first;
        int dist = Queue.front().second;
        Queue.pop();

        if (x == target)
        {
            return dist;
        }

        for (const auto& item : Graph[x])
        {
            if (!visited[item])
            {
                Queue.push({item, dist + 1});
                visited[item] = true;
            }
        }
    }

    return -1;
}

int main()
{
    int N;
    cin >> N;

    int start, end;
    cin >> start >> end;

    int m;

    cin >> m;

    vector<vector<int>> Graph;
    vector<bool> Visited;

    Graph.resize(N + 1);
    Visited.resize(N + 1, false);

    for (int i = 0; i < m; i++)
    {
        int parent, child;

        cin >> parent >> child;

        Graph[parent].push_back(child);
        Graph[child].push_back(parent);
    }

    cout << BFS(Graph, Visited, start, end) << "\n";

    return 0;
}
