#include <bits/stdc++.h>

using namespace std;

int findParent(vector<int>& parent, int x) {
  if (parent[x] != x)
    parent[x] = findParent(parent, parent[x]);
  return parent[x];
}

void unionSets(vector<int>& parent, int a, int b) {
  a = findParent(parent, a);
  b = findParent(parent, b);

  if (a < b)
    parent[b] = a;
  else
    parent[a] = b;
}

struct Edge {
  int from, to, weight;
};

int kruskal(vector<Edge>& edges, int V) {
  sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
    return a.weight < b.weight;
  });

  vector<int> parent(V + 1);
  for (int i = 1; i <= V; ++i)
    parent[i] = i;

  int result = 0;
  for (const Edge& edge : edges) {
    if (findParent(parent, edge.from) != findParent(parent, edge.to)) {
      unionSets(parent, edge.from, edge.to);
      result += edge.weight;
    }
  }

  return result;
}

int main() {
//  freopen("input.txt", "r", stdin);
  
  int V, E;
  cin >> V >> E;

  vector<Edge> edges;
  for (int i = 0; i < E; ++i) {
    int A, B, C;
    cin >> A >> B >> C;
    edges.push_back({A, B, C});
  }

  int result = kruskal(edges, V);
  cout << result << endl;

  return 0;
}
