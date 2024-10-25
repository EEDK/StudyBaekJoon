#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int len = weak.size();
    
    for(int i = 0; i < len; i++){
        weak.push_back(weak[i] + n);
    }

    
    int answer = dist.size() + 1;
    
    for(int start = 0; start < len; start++){
        do{
            int cnt = 1;
            int pos = weak[start] + dist[cnt - 1];
            
            for(int idx = start; idx < start + len; idx++){
                if(pos < weak[idx]){
                    cnt+=1;
                    if(cnt > dist.size()){
                        break;
                    }
                    pos= weak[idx] + dist[cnt - 1];
                }
            }
            
            answer = min(answer, cnt);
            
        }while(next_permutation(dist.begin(), dist.end()));
    }
    
    
    return answer > dist.size() ? -1 : answer;
}