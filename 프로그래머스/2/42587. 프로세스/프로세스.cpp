#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    // 우선순위, 기존순번
    queue<pair<int, int>> queue;
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); i++){
        pq.push(priorities[i]);
        queue.push({priorities[i], i});
    }
    
    while(!queue.empty()){
        int max = pq.top();
        int now = queue.front().first;
        int idx = queue.front().second;
        
        if(max > now){
            queue.pop();
            queue.push({now, idx});
        }
        else{
            queue.pop();
            pq.pop();
            answer++;
            if(idx == location){
                break;
            }
        }        
        
    }
                
    return answer;
}