#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m;

bool IsValid(const vector<vector<int>>& board, int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 1);
}

pair<bool, int> BackTrack(vector<vector<int>>& board, vector<int>& cur, vector<int>& opp) {
    int x = cur[0], y = cur[1];
    if (!IsValid(board, x, y)) return {false, 0}; 
    
    bool canWin = false;
    int maxMoves = 0, minMoves = INT_MAX;
    
    board[x][y] = 0; 
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (IsValid(board, nx, ny)) {
            cur = {nx, ny};  
            auto result = BackTrack(board, opp, cur);  
            bool oppCanWin = result.first;
            int moves = result.second + 1;  

            if (!oppCanWin) {  
                canWin = true;
                minMoves = min(minMoves, moves);  
            } else {  
                maxMoves = max(maxMoves, moves);  
            }
            cur = {x, y}; 
        }
    }

    board[x][y] = 1; 

    if (canWin) return {true, minMoves};
    return {false, maxMoves};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    n = board.size();
    m = board[0].size();
    
    auto result = BackTrack(board, aloc, bloc);
    return result.second;  
}
