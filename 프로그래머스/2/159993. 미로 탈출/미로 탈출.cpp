#include <bits/stdc++.h>

using namespace std;

// (S -> L) + (L -> E)

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int BFS(vector<string> maps, vector<vector<int>> &Visited, pair<int, int> startPos, pair<int, int> endPos){
    
    queue<pair<int, int>> Queue;
    
    Visited[startPos.first][startPos.second] = 0;
    Queue.push(startPos);
    
    while(!Queue.empty()){
        int x = Queue.front().first;
        int y = Queue.front().second;
        Queue.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size()) continue;
            
            else if(maps[nx][ny] == 'X' || Visited[nx][ny] > 0) continue;
            
            Visited[nx][ny] = Visited[x][y] + 1;
            Queue.push({nx, ny});
        }
    }
        
    return Visited[endPos.first][endPos.second];
}

int solution(vector<string> maps) {
    int answer = 0;
    
    int sizeX = maps.size();
    int sizeY = maps[0].size();
    
    vector<vector<int>> Visited(sizeX, vector<int>(sizeY, 0));
    
    pair<int,int> startPos;
    pair<int,int> leverPos;
    pair<int,int> endPos;
    
    for(int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY; j++){
            if(maps[i][j] == 'S'){
                startPos = {i, j};
            }
            else if(maps[i][j] == 'L'){
                leverPos = {i, j};
            }
            else if(maps[i][j] == 'E'){
                endPos = {i, j};
            }
        }
    }
    
    int toLever = BFS(maps, Visited, startPos, leverPos);
    vector<vector<int>> newVisited(sizeX, vector<int>(sizeY, 0));
    int toEnd = BFS(maps, newVisited, leverPos, endPos);
    
    if(toLever == 0 || toEnd == 0){
        answer = -1;
    }
    
    else{
        answer = toLever + toEnd;
    }
    
    return answer;
}