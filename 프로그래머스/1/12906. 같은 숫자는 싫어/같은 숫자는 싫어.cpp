#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    stack<int> Stack;
    Stack.push(arr[0]);
    answer.push_back(arr[0]);
    
    for(int i = 1; i < arr.size(); i++){
        if(!Stack.empty() && arr[i] == Stack.top()){
            continue;
        }
        else{
            Stack.push(arr[i]);
            answer.push_back(arr[i]);
        }
        
    }

    return answer;
}