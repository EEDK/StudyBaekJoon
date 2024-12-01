#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    int cameraPos = routes[0][1];
    for(const auto& route: routes){
        int start = route[0];
        int end = route[1];
        
        if(start > cameraPos){
            cameraPos = end;
            answer++;
        }
    }
    
    return answer;
}