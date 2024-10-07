#include <bits/stdc++.h>
using namespace std;

vector<int> answer;

vector<int> DiscountPercent = {40, 30, 20, 10};
vector<pair<int, int>> Temp;

int Discount(int Price, int Discount){
    return (Price * (100 - Discount)) / 100;
}

bool IsChange(const vector<int>& a, const vector<int>& b){
    if (a[0] > b[0]) {  
        return true;
    } else if (a[0] == b[0]) { 
        if (a[1] > b[1]) {
            return true;
        }
    }
    return false;
}

void BackTrack(const vector<vector<int>>& users, const vector<int>& emoticons, int posEmoticon) {
    if (posEmoticon == emoticons.size()) {
        vector<int> TempResult(2, 0);
        
        for (const auto& user : users) {
            int TargetDiscount = user[0];
            int TargetAmount = user[1];
            
            int sum = 0;
            
            for (const auto& pair : Temp) {
                if (TargetDiscount <= pair.second) {
                    sum += Discount(pair.first, pair.second);
                }
            }
            
            if (sum >= TargetAmount) {
                TempResult[0]++; 
            } else {
                TempResult[1] += sum;
            }
        }
        
        if (IsChange(TempResult, answer)) {
            answer = TempResult;
        }
        
        return;
    }

    for (int i = 0; i < DiscountPercent.size(); i++) {
        Temp.push_back({emoticons[posEmoticon], DiscountPercent[i]});
        BackTrack(users, emoticons, posEmoticon + 1);
        Temp.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {    
    answer = {0, 0};
    
    BackTrack(users, emoticons, 0);
    
    return answer;
}
