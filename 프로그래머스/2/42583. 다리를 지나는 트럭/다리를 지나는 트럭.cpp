#include <bits/stdc++.h>

using namespace std;

int sum(const vector<int>& vec) {
    int total = 0;
    for (const int& item : vec) {
        total += item;
    }
    return total;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int target = truck_weights.size(); 

    queue<int> waiting_trucks; 
    for (const int& truck_weight : truck_weights) {
        waiting_trucks.push(truck_weight);
    }
    
    queue<int> bridge;
    vector<int> time_on_bridge; 

    int nowWeight = 0; 
    int endCnt = 0; 

    while (endCnt < target) {
        answer++; 

        if (!bridge.empty()) {
            if (time_on_bridge.front() >= bridge_length) {
                nowWeight -= bridge.front(); 
                bridge.pop(); 
                time_on_bridge.erase(time_on_bridge.begin()); 
                endCnt++; 
            }
        }

        if (!waiting_trucks.empty() && nowWeight + waiting_trucks.front() <= weight) {
            int truck_weight = waiting_trucks.front();
            waiting_trucks.pop();
            bridge.push(truck_weight);
            time_on_bridge.push_back(0);
            nowWeight += truck_weight;
        }

        for (int i = 0; i < time_on_bridge.size(); i++) {
            time_on_bridge[i]++;
        }
    }

    return answer;
}
