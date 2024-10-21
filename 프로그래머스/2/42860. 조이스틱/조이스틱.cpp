#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    
    for (int i = 0; i < n; i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
    }
    
    int min_move = n - 1; 
    for (int i = 0; i < n; i++) {
        int next_idx = i + 1;
        while (next_idx < n && name[next_idx] == 'A') {
            next_idx++;
        }
        min_move = min(min_move, i + n - next_idx + min(i, n - next_idx));
    }
    answer += min_move;
    
    return answer;
}
