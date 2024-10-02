#include <bits/stdc++.h>

using namespace std;

int N, M;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

bool isRange(int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int BFS(vector<string> maps, vector<vector<bool>> &Visited, pair<int, int> Pos){
    int sum = (maps[Pos.first][Pos.second] - '0');
    Visited[Pos.first][Pos.second] = true;
    
    queue<pair<int, int>> Queue;
    Queue.push(Pos);
    
    while(!Queue.empty()){
        int x = Queue.front().first; 
        int y = Queue.front().second;

        Queue.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isRange(nx, ny) && maps[nx][ny] != 'X' && !Visited[nx][ny]){
                Queue.push({nx, ny});
                sum += (maps[nx][ny] - '0');
                Visited[nx][ny] = true;
            }
        }
    }
    
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    N = maps.size();
    M = maps[0].size();
    
    vector<vector<bool>> Visited(N, vector<bool>(M, false));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!Visited[i][j] && maps[i][j] != 'X'){
                answer.push_back(BFS(maps, Visited, {i, j}));
            }
        }
    }

    if(answer.size() == 0){
        answer.push_back(-1);
    }
    
    else{
        sort(answer.begin(), answer.end());
    }
    
    return answer;
}