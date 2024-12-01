#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    sort(jobs.begin(), jobs.end());
    
    int currentTime = 0, totalTime = 0, index = 0, n = jobs.size();
    
    while (!pq.empty() || index < n) {
        while (index < n && jobs[index][0] <= currentTime) {
            pq.push({jobs[index][1], jobs[index][0]});
            index++;
        }

        if (!pq.empty()) {
            int duration = pq.top().first;
            int requestTime = pq.top().second;
            pq.pop();

            currentTime += duration;
            totalTime += currentTime - requestTime;
        } else {
            currentTime = jobs[index][0];
        }
    }
    
    return totalTime / n;
}
