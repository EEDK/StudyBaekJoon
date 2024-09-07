#include <bits/stdc++.h>

using namespace std;

void dfs(const string& airport, map<string, vector<string>>& graph, vector<string>& route) {
    while (!graph[airport].empty()) {
        string next_airport = graph[airport].back();
        graph[airport].pop_back();
        dfs(next_airport, graph, route);
    }
    route.push_back(airport);
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    map<string, vector<string>> graph;
    for (const auto& ticket : tickets) {
        graph[ticket[0]].push_back(ticket[1]);
    }
    
    for (auto& [key, destinations] : graph) {
        sort(destinations.rbegin(), destinations.rend());
    }
    
    vector<string> route;
    dfs("ICN", graph, route);

    reverse(route.begin(), route.end());
    return route;
}