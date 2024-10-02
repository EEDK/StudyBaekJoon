#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    vector<vector<int>> new_sizes;
    
    for(const auto& size : sizes){
        vector<int> tmp;
        if(size[0] < size[1]){
            tmp.push_back(size[1]);
            tmp.push_back(size[0]);
        }
        else{
            tmp.push_back(size[0]);
            tmp.push_back(size[1]);
        }
        new_sizes.push_back(tmp);
    }
    
    int max_X = INT_MIN;
    int max_Y = INT_MIN;
    
    for(const auto& size : new_sizes){        
        if(max_X < size[0]){
            max_X = size[0];
        }
        
        if(max_Y < size[1]){
            max_Y = size[1];
        }
    }
    
    return max_X * max_Y;
}