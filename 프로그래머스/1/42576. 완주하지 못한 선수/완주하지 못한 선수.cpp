#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_map<string, int> participants;
    
    for(string str : participant){
        if(!participants[str]){
            participants[str] = 1;
        }
        else{
            participants[str] += 1;
        }
    }
    
    for(string str : completion){
        participants[str] -= 1;
    }
    
    for(string str : participant){
        if(participants[str] != 0){
            return str;
        }
    }

    return "1";
}
