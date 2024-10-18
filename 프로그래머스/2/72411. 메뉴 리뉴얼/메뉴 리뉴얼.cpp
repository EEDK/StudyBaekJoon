#include <bits/stdc++.h>

using namespace std;

string tempCourse;
unordered_map<string, int> Maps;

void BackTrack(string& order, int pos, int r){
    if(tempCourse.size() == r){
        Maps[tempCourse]++;
        return;
    }
    
    if(pos >= order.size()){
        return;
    }
    
    tempCourse.push_back(order[pos]);
    BackTrack(order, pos+1, r);
    tempCourse.pop_back();
    BackTrack(order, pos+1, r);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(const int& c : course){
        Maps.clear();
        
        for(string order : orders){
            sort(order.begin(), order.end());
            BackTrack(order, 0, c);
        }

        int max_count = 2; 
        for(const auto& item : Maps){
            if(item.second > max_count) max_count = item.second;
        }

        for(const auto& item : Maps){
            if(item.second == max_count){
                answer.push_back(item.first);
            }
        }
    }

    sort(answer.begin(), answer.end()); 
    
    return answer;
}
