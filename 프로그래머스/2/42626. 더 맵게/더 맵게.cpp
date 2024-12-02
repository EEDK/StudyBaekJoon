#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(pq.top() < K && pq.size() >= 2){
        int smallst = pq.top();
        pq.pop();
        int secondSmall = pq.top();
        pq.pop();
        
        int newScovile = smallst + (secondSmall * 2);
        pq.push(newScovile);
        answer++;
    }
    
    if(pq.top() < K){
        return -1;
    }


    return answer;
}