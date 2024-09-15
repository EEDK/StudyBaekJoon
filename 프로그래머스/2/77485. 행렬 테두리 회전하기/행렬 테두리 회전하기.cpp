#include <bits/stdc++.h>

using namespace std;

int Spin(vector<vector<int>> &Graph, pair<int, int> startPos, pair<int, int> endPos){
    vector<vector<int>> tempGraph = Graph;

    int x1 = startPos.first;
    int y1 = startPos.second;
        
    int x2 = endPos.first;
    int y2 = endPos.second;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = y1; i < y2; i++) {
        tempGraph[x1][i + 1] = Graph[x1][i];
        pq.push(tempGraph[x1][i+1]);
    }
    
    for (int i = x1; i < x2; i++) {
        tempGraph[i + 1][y2] = Graph[i][y2];
        pq.push(tempGraph[i + 1][y2]);
    }
    
    for (int i = y2; i > y1; i--) {
        tempGraph[x2][i - 1] = Graph[x2][i];
        pq.push(tempGraph[x2][i - 1]);
    }
    
    for (int i = x2; i > x1; i--) {
        tempGraph[i - 1][y1] = Graph[i][y1];
        pq.push(tempGraph[i - 1][y1]);
    }
    
    Graph = tempGraph;
    
    return pq.top();
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> Graph(rows, vector<int>(columns, 0));
    int cnt = 1;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            Graph[i][j] = cnt;
            cnt++;
        }
    }
    
    
    for(const auto& query : queries){
        int x1 = query[0] - 1;
        int y1 = query[1] - 1;
        
        int x2 = query[2] - 1;
        int y2 = query[3] - 1;
        
        answer.push_back(Spin(Graph, {x1, y1}, {x2, y2}));
    }
    
    return answer;
}