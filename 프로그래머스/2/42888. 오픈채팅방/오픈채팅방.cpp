#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> map;
    
    for(string str : record){
        stringstream ss(str);
        
        string ptr, uid, userName;
        
        ss >> ptr >> uid >> userName;
        
        if(ptr == "Enter" || ptr == "Change") {
            ss >> userName; 
            map[uid] = userName;  
        }    
    }
    
    for(string str : record){
        stringstream ss(str);
        
        string ptr, uid, userName;
        
        ss >> ptr >> uid;
        
        if(ptr == "Enter"){
            string pre = map[uid];
            string In = "님이 들어왔습니다.";
            answer.push_back(pre+In);
        }
        
        else if(ptr == "Leave"){
            string pre = map[uid];
            string Out = "님이 나갔습니다.";
            answer.push_back(pre+Out);
        }
        
    }
    
    return answer;
}