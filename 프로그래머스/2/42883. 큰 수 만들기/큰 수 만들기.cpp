#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = ""; 
    int size = number.size() - k;
    
    for (char digit : number) {
        while(!answer.empty() && k > 0 && answer.back() < digit){
            answer.pop_back();
            k--;
        }
        answer.push_back(digit);
    }
    
    answer = answer.substr(0, size);
    return answer;
}