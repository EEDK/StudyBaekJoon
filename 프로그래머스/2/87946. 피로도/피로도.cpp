#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int maxSize = dungeons.size();
    vector<int> numbers;
    
    for(int i = 0; i < maxSize; i++){
        numbers.push_back(i);
    }
    
    vector<vector<int>> permutations;
    
    do{
        permutations.push_back(numbers);
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    
    vector<int> Lst;
    
    for(const auto& item: permutations){
        int i = 0;
        int now = k;
        for(int num : item){
            if(dungeons[num][0] <= now && now - dungeons[num][1] >= 0){
                i++;
                if(i == maxSize){
                    return maxSize;
                }
                now -= dungeons[num][1];
            }
            
            else{
                break;
            }
        }
        
        Lst.push_back(i);
    }
    
    
    return *max_element(Lst.begin(), Lst.end());
}