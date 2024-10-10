#include <bits/stdc++.h>

using namespace std;

bool canCross(const vector<int>& stones, int k, int people) {
    int jump = 0;
    for (int stone : stones) {
        if (stone < people) {
            jump++;
            if (jump >= k) {
                return false;
            }
        } else {
            jump = 0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int left = 1;
    int right = *max_element(stones.begin(), stones.end());
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (canCross(stones, k, mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return answer;
}
