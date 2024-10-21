#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int bfs(vector<vector<int>> picture, vector<vector<bool>> &Visited, pair<int, int> Pos, int Val){
    int x = Pos.first;
    int y = Pos.second;
    
    int m = picture.size();
    int n = picture[0].size();
    
    Visited[x][y] = true;
    
    int result = 1;
    
    queue<pair<int, int>> Queue;
    Queue.push(Pos);
    
    while(!Queue.empty()){
        int x = Queue.front().first;
        int y = Queue.front().second;
        Queue.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !Visited[nx][ny] && picture[nx][ny] == Val){
                Visited[nx][ny] = true;
                Queue.push({nx, ny});
                result++;
            }
        }
    }
    
    return result;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<bool>> Visited(m, vector<bool>(n, false));
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(picture[i][j] != 0 && !Visited[i][j]){
                int nowSize = bfs(picture, Visited, {i,j}, picture[i][j]);
                 if(nowSize > max_size_of_one_area){
                     swap(nowSize, max_size_of_one_area);
                }
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}