#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = 1;
    int idx = 0;
    
    while(start <= n){
        if(idx < stations.size() && start >= stations[idx] - w){
            start = stations[idx] + w + 1;
            idx++;
        }
        else{
            start += 2*w + 1;
            answer++;
        }
    }
 
    return answer;
}