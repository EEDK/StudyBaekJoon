#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (s < n) {
        return {-1};
    }
    
    int quotient = s / n;
    int remainder = s % n;
    
    vector<int> result(n, quotient); 
    for (int i = 0; i < remainder; ++i) {
        result[i] += 1; 
    }

    sort(result.begin(), result.end());
    
    return result;
}