#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    unordered_map<string, int> GiftPoints;
    unordered_map<string, unordered_map<string, int>> map;
    
    for(int i = 0; i < friends.size(); i++){
        GiftPoints[friends[i]] = 0;
    }
    
    for(const auto& gift : gifts){
        stringstream ss(gift);
        string u, v;
        
        ss >> u >> v;
        
        GiftPoints[u] += 1;
        GiftPoints[v] -= 1;
        
        map[u][v] += 1;
    }
    
    vector<int> NextGift(friends.size(), 0);
    
    for(int i = 0; i < friends.size(); i++){
        for(int j = i + 1; j < friends.size(); j++){
            string u = friends[i];
            string v = friends[j];
            
            if(map[u][v] > map[v][u]){
                NextGift[i]++;
            }
            
            else if(map[u][v] < map[v][u]){
                NextGift[j] ++;
            }
            
            else{
                
                if(GiftPoints[u] > GiftPoints[v]){
                    NextGift[i]++;
                }
                else if(GiftPoints[u] < GiftPoints[v]){
                    NextGift[j]++;
                }
            }
        }
    }

    return *max_element(NextGift.begin(), NextGift.end());
}