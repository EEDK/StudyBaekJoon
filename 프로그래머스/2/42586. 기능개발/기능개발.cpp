#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> Queue;
    
    for(const int& progress : progresses){
        Queue.push(progress);
    }
    
    int days = 0;
    int idx = 0;
    
    int cnt = 0;
    while(!Queue.empty()){
        int now = Queue.front();
        Queue.pop();
        
        int needDays = ceil(float(100 - progresses[idx]) / speeds[idx]);
        idx++;
        
        if(days >= needDays){
            cnt++;
        }
        else{
            if(cnt > 0){
                answer.push_back(cnt);
            }
            cnt = 1;
            days = needDays;
        }
    }
    
    if (cnt > 0) {
        answer.push_back(cnt);
    }
    
    return answer;
}