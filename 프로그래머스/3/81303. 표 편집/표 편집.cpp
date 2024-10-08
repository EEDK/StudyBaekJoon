#include <bits/stdc++.h>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    stack<int> deleted;
    
    vector<int> up;
    vector<int> down;
    
    for(int i = 0; i < n + 2; i++){
        up.push_back(i - 1);
        down.push_back(i + 1);
    }
    
    k++;
    
    for(const auto& command : cmd){
        if(command[0] == 'C'){
            deleted.push(k);
            down[up[k]] = down[k];
            up[down[k]] = up[k];
            
            if(down[k] == n+1){
                k = up[k];
            }
            else{
                k = down[k];
            }
        }
        else if(command[0] == 'Z'){
            int r = deleted.top();
            deleted.pop();
            down[up[r]] = r;
            up[down[r]] = r;
        }
        
        else{
            int sz = stoi(command.substr(2));
            
            if(command[0] == 'U'){
                for(int j = 0; j < sz; j++){
                    k = up[k];
                }
            }
            
            else{
                for(int j = 0; j < sz; j++){
                    k = down[k];
                }
            }
        }
    }
    string answer;
    
    answer.append(n, 'O');
    while(!deleted.empty()){
        answer[deleted.top() - 1] = 'X';
        deleted.pop();
    }
    
    return answer;
}