#include <bits/stdc++.h>

using namespace std;


int solution(vector<int> nums) {
    
    unordered_map<int, int> Lst;
    
    int cnt = 0;

    for(int i = 0; i < nums.size(); ++i){
        if(Lst[nums[i]]){
            Lst[nums[i]] += 1;
        }
        else{
            cnt++;
            Lst[nums[i]] = 1;
        }
    
    }
    
    if(nums.size() / 2  <= cnt){
        return nums.size() / 2;    
    }
    
    else{
        return cnt;
    }

}
