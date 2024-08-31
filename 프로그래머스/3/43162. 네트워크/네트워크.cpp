#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> computers, vector<bool>& visited, int start){
    visited[start] = true;
    
    for(int i = 0; i < computers.size(); i++){
        if(computers[start][i] == 1 && !visited[i]){
            dfs(computers, visited, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(computers, visited, i);
            answer++;
        }
    }
    
    return answer;
}