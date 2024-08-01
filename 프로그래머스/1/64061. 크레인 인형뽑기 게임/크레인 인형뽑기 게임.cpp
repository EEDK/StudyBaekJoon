#include <bits/stdc++.h>

using namespace std;

// [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]	
// [1,5,3,5,1,2,1,4]

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> bascket;
    
    for(int target : moves){
        for(int i = 0; i < board.size(); i++){
            if(!board[i][target - 1] == 0){
                if(!bascket.empty() && bascket.top() == board[i][target - 1]){
                    answer += 2;
                    bascket.pop();
                }
                else{
                    bascket.push(board[i][target - 1]);
                }
                board[i][target - 1] = 0;
                break;
            }
        }
    }
    

    return answer;
}