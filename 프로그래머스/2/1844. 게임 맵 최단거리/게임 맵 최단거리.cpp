#include <bits/stdc++.h>

using namespace std;

const vector<int> dx{-1, 0, 1, 0};
const vector<int> dy{0, -1, 0, 1};

static int n;
static int m;

int bfs(vector<vector<int> > maps, vector<vector<int>> &Visited){
    
    queue<pair<int, int>> Queue;
    
    Queue.push({0, 0});
    Visited[0][0] = 1;
    
    while(!Queue.empty()){
        int x = Queue.front().first;
        int y = Queue.front().second;
        Queue.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            
            else if(maps[nx][ny] == 0 || Visited[nx][ny] > 0) continue;
            
            Visited[nx][ny] = Visited[x][y] + 1;
            Queue.push({nx, ny});
        }
        
    }
        
    return Visited[n-1][m-1];
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    
    vector<vector<int>> Visited(n, vector<int>(m, 0));
    
    return bfs(maps, Visited) == 0 ? -1 : bfs(maps, Visited);
}