#include <bits/stdc++.h>

using namespace std;

int dfs(int v, vector<bool>& visited, vector<vector<int>>& graph) {
    visited[v] = true;
    int cnt = 1;
    for (int i : graph[v]) {
        if (!visited[i]) {
            cnt += dfs(i, visited, graph);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    for (int i = 0; i < wires.size(); ++i) {
        vector<vector<int>> graph(n + 1);
        vector<bool> visited(n + 1, false);
        for (int j = 0; j < wires.size(); ++j) {
            if (i == j) continue;
            int v1 = wires[j][0];
            int v2 = wires[j][1];
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        
        int cnt1 = dfs(wires[i][0], visited, graph);
        int cnt2 = n - cnt1;
        
        answer = min(answer, abs(cnt1 - cnt2));
    }
    return answer;

}