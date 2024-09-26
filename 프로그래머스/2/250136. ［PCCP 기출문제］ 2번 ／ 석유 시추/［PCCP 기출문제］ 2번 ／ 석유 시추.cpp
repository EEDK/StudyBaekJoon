#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m;

bool IsRange(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void BFS(vector<vector<int>>& land, vector<vector<int>>& Visited, pair<int, int> Pos, int region_id) {
    Visited[Pos.first][Pos.second] = region_id;
    
    int Size = 1;
    
    queue<pair<int, int>> Queue;
    vector<pair<int, int>> TempPos;

    Queue.push(Pos);
    TempPos.push_back(Pos);
    
    while (!Queue.empty()) {
        int x = Queue.front().first;
        int y = Queue.front().second;
        Queue.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (IsRange(nx, ny) && land[nx][ny] == 1 && Visited[nx][ny] == 0) {
                Queue.push({nx, ny});
                Visited[nx][ny] = region_id;
                TempPos.push_back({nx, ny});
                Size++;
            }
        }
    }
    
    for (const auto& temp : TempPos) {
        land[temp.first][temp.second] = Size;
    }
}

int solution(vector<vector<int>> land) {
    n = land.size();
    m = land[0].size();
    
    int answer = 0;
    vector<vector<int>> Visited(n, vector<int>(m, 0));
    int region_id = 2;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (land[i][j] == 1 && Visited[i][j] == 0) {
                BFS(land, Visited, {i, j}, region_id);
                region_id++;
            }
        }
    }
    
    for (int j = 0; j < m; j++) {
        set<int> seen_regions;
        int Result = 0;
        
        for (int i = 0; i < n; i++) {
            int current_size = land[i][j];
            int current_region_id = Visited[i][j];
            
            if (current_size > 0 && seen_regions.find(current_region_id) == seen_regions.end()) {
                Result += current_size;
                seen_regions.insert(current_region_id); // 해당 영역 ID를 추가
            }
        }
        answer = max(answer, Result);
    }
    
    return answer;
}
