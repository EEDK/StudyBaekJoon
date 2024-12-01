#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    stack<int> Stack;
    
    for(int i = 0; i < ingredient.size(); i++){
        Stack.push(ingredient[i]);
        
        if(Stack.size () >= 4){
            int fourth = Stack.top(); 
            Stack.pop();
            int third = Stack.top(); 
            Stack.pop();
            int second = Stack.top(); 
            Stack.pop();
            int first = Stack.top(); 
            Stack.pop();       
            if (first == 1 && second == 2 && third == 3 && fourth == 1) {
                answer++; 
        } 
        else {
            Stack.push(first);
            Stack.push(second);
            Stack.push(third);
            Stack.push(fourth);
        }
        }

    }

    return answer;
}