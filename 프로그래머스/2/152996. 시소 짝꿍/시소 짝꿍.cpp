#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solution(vector<int> weights) {
    ll answer = 0;
    unordered_map<ll, ll> counter;
    
    for (ll w : weights) {
        counter[w]++;
    }
    for (auto& [k, v] : counter) {
        if (v >= 2) {
            answer += v * (v - 1) / 2;
        }
    }
    set<ll> weightSet(weights.begin(), weights.end()); 

    for (ll w : weightSet) {
        if (w * 2 % 3 == 0 && weightSet.find(w * 2 / 3) != weightSet.end()) {
            answer += counter[w] * counter[w * 2 / 3];
        }
        if (w * 2 % 4 == 0 && weightSet.find(w * 2 / 4) != weightSet.end()) {
            answer += counter[w] * counter[w * 2 / 4];
        }
        if (w * 3 % 4 == 0 && weightSet.find(w * 3 / 4) != weightSet.end()) {
            answer += counter[w] * counter[w * 3 / 4];
        }
    }
    
    return answer;
}