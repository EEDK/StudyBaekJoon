#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> Maps;
    
    
    for(const int& item : tangerine){
        Maps[item] += 1;
    }
    
    vector<int> cnt;
    
    for(const auto& item : Maps){
        cnt.push_back(item.second);
    }
    
    sort(cnt.begin(), cnt.end());
    
    int size = tangerine.size();
    int answer = 0;
    
    for(const int& item : cnt){
        if(size - item < k){
            break;
        }
        
        size -= item;
        answer++;
    }
    
    return cnt.size() - answer;
}