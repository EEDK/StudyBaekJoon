#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> TargetMap;
    unordered_map<string, int> NowMap;

    for(int i = 0; i < number.size(); i++){
        TargetMap[want[i]] = number[i];
    }
    
    for(int i = 0; i < 10; i++){
        if(NowMap[discount[i]]){
            NowMap[discount[i]] += 1;
        }
        else{
            NowMap[discount[i]] = 1;
        }    
    }
    
    bool isOk = true;
    for(int i = 0; i < want.size(); i++){
        if(TargetMap[want[i]] != NowMap[want[i]]){
            isOk = false;
            break;
        }
    }
    
    if(isOk){
        answer += 1;
    }
    
    for(int i = 10; i < discount.size(); i++){
        NowMap[discount[i - 10]] -= 1;
        NowMap[discount[i]] += 1;
        
        bool isOk = true;
        for(int i = 0; i < want.size(); i++){
            if(TargetMap[want[i]] != NowMap[want[i]]){
                isOk = false;
                break;
            }
        }

        if(isOk){
            answer += 1;
        }

    }
    
    
    return answer;
}