#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer{0, 0};
    unordered_map<string, bool> list;

    string prev = words[0];
    list[prev] = true;
    
    for(int i = 1; i < words.size(); i++){
        int Turn = i % n + 1;
        int Phase = i / n + 1;
        
        if(prev[prev.size() - 1] != words[i][0] || list[words[i]]){
            answer[0] = Turn;
            answer[1] = Phase;
            
            return answer;
        }
        prev = words[i];
        list[words[i]] = true;
    }

    return answer;
}