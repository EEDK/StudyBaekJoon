#include <bits/stdc++.h>

using namespace std;

int answer = 0;

void DFS(vector<int> numbers, int sum, int pos, int target){
    if (pos == numbers.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }
    
    DFS(numbers, sum + numbers[pos], pos + 1, target);
    DFS(numbers, sum - numbers[pos], pos + 1, target);
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, 0, 0, target);
    
    return answer;
}