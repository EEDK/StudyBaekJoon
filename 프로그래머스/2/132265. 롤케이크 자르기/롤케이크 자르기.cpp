#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int, int> leftMap, rightMap;
    for (int t : topping) {
        rightMap[t]++;
    }
    
    for (int i = 0; i < topping.size(); i++) {
        leftMap[topping[i]]++;
        if (--rightMap[topping[i]] == 0) {
            rightMap.erase(topping[i]);
        }
        if (leftMap.size() == rightMap.size()) {
            answer++;
        }
    }
    
    return answer;
}