#include <bits/stdc++.h>

using namespace std;

const int DayMinute = 23 * 60 + 59;

unordered_map<int, int> ParkingMap; 
unordered_map<int, int> AccumulatedTime; 
vector<pair<int, int>> Result;

int base_time;
int base_money;
int split_time;
int split_money;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    base_time = fees[0];
    base_money = fees[1];
    split_time = fees[2];
    split_money = fees[3];
    
    for (const auto& record : records) {
        int hour = stoi(record.substr(0, 2));
        int minutes = stoi(record.substr(3, 2));
        int number = stoi(record.substr(6, 4));
        int time = hour * 60 + minutes;
        
        string action = record.substr(11);
        
        if (action == "IN") {
            ParkingMap[number] = time;
        } 
        else if (action == "OUT") {
            int startTime = ParkingMap[number];
            AccumulatedTime[number] += time - startTime;
            ParkingMap.erase(number);
        }
    }
    
    for (const auto& entry : ParkingMap) {
        int number = entry.first;
        int startTime = entry.second;
        AccumulatedTime[number] += DayMinute - startTime;
    }
    
    for (const auto& entry : AccumulatedTime) {
        int number = entry.first;
        int totalTime = entry.second;
        
        int totalFee = base_money;
        if (totalTime > base_time) {
            totalFee += ceil((double)(totalTime - base_time) / split_time) * split_money;
        }
        
        Result.push_back({number, totalFee});
    }
    
    sort(Result.begin(), Result.end());
    
    for (const auto& pair : Result) {
        answer.push_back(pair.second);
    }
    
    return answer;
}
