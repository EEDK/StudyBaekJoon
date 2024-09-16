#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 1, 0, 1};
const int dy[] = {0, 0, 1, 1};

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int PreValue = -1;
    
    while(answer > PreValue) {
        PreValue = answer;
        
        queue<pair<int, int>> Pos;
        vector<vector<bool>> marked(m, vector<bool>(n, false));
        
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n - 1; j++) {
                char a = board[i][j];
                char b = board[i][j + 1];
                char c = board[i + 1][j];
                char d = board[i + 1][j + 1];
                
                if(a != '0' && a == b && b == c && c == d) {
                    marked[i][j] = marked[i][j + 1] = marked[i + 1][j] = marked[i + 1][j + 1] = true;
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(marked[i][j]) {
                    board[i][j] = '0';
                    answer++;
                }
            }
        }
        
        for(int j = 0; j < n; j++) {
            int emptyRow = m - 1; 
            for(int i = m - 1; i >= 0; i--) {
                if(board[i][j] != '0') {
                    swap(board[i][j], board[emptyRow][j]);
                    emptyRow--;
                }
            }
        }
    }
    
    return answer;
}
