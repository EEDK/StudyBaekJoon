#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0 ,-1, 0, 1};

void bfs(const vector<string>& board, vector<vector<int>>& Visited, pair<int, int> StartPos, pair<int, int> GoalPos){
    
    int n = board.size();
    int m = board[0].size();
    
    queue<pair<int, int>> Queue;
    
    Queue.push(StartPos);
    
    Visited[StartPos.first][StartPos.second] = 1;
    
    while (!Queue.empty()) {
        int x = Queue.front().first;
        int y = Queue.front().second;
        Queue.pop();

        if (make_pair(x, y) == GoalPos) return;

        for (int i = 0; i < 4; i++) {
            int nx = x, ny = y;

            while (true) {
                int tx = nx + dx[i];
                int ty = ny + dy[i];

                if (tx < 0 || tx >= n || ty < 0 || ty >= m || board[tx][ty] == 'D') break;

                nx = tx;
                ny = ty;
            }

            if (Visited[nx][ny]) continue;

            Visited[nx][ny] = Visited[x][y] + 1;
            Queue.push({nx, ny});
        }
    }

}

int solution(vector<string> board) {    
    pair<int, int> StartPos;
    pair<int, int> GoalPos;
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == 'R') StartPos = {i,j}; 
            if(board[i][j] == 'G') GoalPos = {i,j}; 
        }
    }
    
    vector<vector<int>> Visited(board.size() + 1, vector<int>(board[0].size() + 1, 0));

    bfs(board, Visited, StartPos, GoalPos);
    
    return Visited[GoalPos.first][GoalPos.second] - 1;
}