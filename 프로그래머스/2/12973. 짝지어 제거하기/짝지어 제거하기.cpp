#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    stack<char> Stack;
    
    for(char str : s){
        if (!Stack.empty() && Stack.top() == str) {
            Stack.pop();
        } else {
            Stack.push(str);
        }
    }
    
    return Stack.empty() ? 1 : 0;
}