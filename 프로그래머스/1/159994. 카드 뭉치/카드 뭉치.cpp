#include <bits/stdc++.h>

using namespace std;

queue<string> makeQueue(vector<string> input){
    queue<string> result;
    
    for(auto item : input){
        result.push(item);
    }
    
    return result;
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> GoalQueue = makeQueue(goal);
    queue<string> CardQueue1 = makeQueue(cards1);
    queue<string> CardQueue2 = makeQueue(cards2);
    
    while(!GoalQueue.empty()){
        string temp = GoalQueue.front();
        string Card1 = CardQueue1.front();
        string Card2 = CardQueue2.front();
        
        if(temp == Card1){
            CardQueue1.pop();
        }
        
        else if(temp == Card2){
            CardQueue2.pop();
        }
        
        else{
            return "No";
        }
        
        GoalQueue.pop();
    }
    
    return "Yes";
}