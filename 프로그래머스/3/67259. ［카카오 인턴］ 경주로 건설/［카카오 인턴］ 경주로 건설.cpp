#include <bits/stdc++.h>

using namespace std;

static int N;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

struct Path{
    int y, x, direction;
};

int solution(vector<vector<int>> board) {    
    N = board.size();
    int Dist[26][26][4];
    memset(Dist, -1, sizeof(Dist));
    
    queue<Path> q;
    
    q.push({0, 0, 1});
    q.push({0, 0, 3});
    
    while(!q.empty()){
        auto [y, x, dir] = q.front();
        q.pop();
        
        int lastCost = Dist[y][x][dir];
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N || board[ny][nx]) continue;
            
            int newCost = lastCost + (i == dir ? 100 : 600);
            
            if(Dist[ny][nx][i] == -1 || Dist[ny][nx][i] > newCost){
                Dist[ny][nx][i] = newCost;
                q.push({ny, nx, i});
            }
        }
    }
    
    int answer = INT_MAX;
    
    for(int i = 0; i < 4; i++){
        if(Dist[N - 1][N - 1][i] != -1){
            answer = min(answer, Dist[N - 1][N - 1][i]);
        }
    }
    
    return answer + 1;
}