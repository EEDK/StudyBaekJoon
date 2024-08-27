#include <bits/stdc++.h>

using namespace std;

int solution(string dirs) {
    set<pair<pair<int, int>, pair<int, int>>> visited; 
    pair<int, int> pos(0, 0); 
    
    int max_x = 5, max_y = 5;
    int min_x = -5, min_y = -5;
    
    for(char op : dirs){
        pair<int, int> new_pos = pos;
        
        if(op == 'L' && pos.first > min_x){
            new_pos.first -= 1;
        } else if(op == 'R' && pos.first < max_x){
            new_pos.first += 1;
        } else if(op == 'D' && pos.second > min_y){
            new_pos.second -= 1;
        } else if(op == 'U' && pos.second < max_y){
            new_pos.second += 1;
        }
        
        if(new_pos != pos) { 
            visited.insert({pos, new_pos});
            visited.insert({new_pos, pos});
            pos = new_pos; 
        }
    }
    
    return visited.size() / 2;
}
