#include <bits/stdc++.h>
using namespace std;

int answer = 0;

void BackTrack(vector<int>& number, int pos, int cnt, int sum) {
    if (cnt == 3) {
        if (sum == 0) {
            answer++;
        }
        return;
    }
    if (pos >= number.size()) {
        return;
    }
    
    BackTrack(number, pos + 1, cnt + 1, sum + number[pos]);
    BackTrack(number, pos + 1, cnt, sum);
}

int solution(vector<int> number) {
    BackTrack(number, 0, 0, 0);
    return answer;
}
