#include <bits/stdc++.h>

using namespace std;


int solution(vector<vector<int>> board) {
    int n = board.size();
    int m = board[0].size();
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(board[i][j] == 1){
                int up = board[i-1][j];
                int left = board[i][j-1];
                int up_left = board[i-1][j-1];
                
                board[i][j] = min(min(up, left), up_left) + 1;
            }
        }
    }
    
    int maxVal = 0;
    for(const auto& row : board){
        maxVal = max(maxVal, *max_element(row.begin(), row.end()));
    }

    return maxVal * maxVal; 
}
