#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll solution(int n, vector<int> times) {
    ll left = 1;
    ll right = (long long)*max_element(times.begin(), times.end()) * n;
    
    ll answer = right;
    
    while(left <= right){
        ll mid = (left + right) / 2;
        ll total = 0;
        
        for(const auto& time : times){
            total += mid / time;
        }
        if (total >= n) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}