#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int answer = 1;
    int last_end = targets[0][1];  

    for (const auto& target : targets) {
        if (target[0] >= last_end) {
            answer++;
            last_end = target[1]; 
        }
    }

    return answer;
}