#include <bits/stdc++.h>

using namespace std;

unordered_map<char, char> bracketPair = {{')', '('}, {']', '['}, {'}', '{'}};

bool IsValid(string &s, int start){
    stack<char> Stack;
    int Size = s.size();
    
    for(int i = 0; i < Size; i++){
        char ch = s[(start + i) % Size];
        
        if(bracketPair.count(ch)){
            
            if(Stack.empty() || Stack.top() != bracketPair[ch]){
                return false;
            }
            
            Stack.pop();
        } else {
            Stack.push(ch);
        }
    }
    
    return Stack.empty();
}

int solution(string s) {
    int answer = 0;
    
    int n = s.size();
    
    for(int i = 0; i < n; i++){
        answer += IsValid(s, i);
    }
    
    return answer;
}