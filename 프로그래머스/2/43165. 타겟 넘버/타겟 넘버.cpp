#include <bits/stdc++.h>

using namespace std;

int answer = 0;

void DFS(vector<int> numbers, int target, int pos, int sum){
    if(pos == numbers.size()){
        if(sum == target){
            answer++;
        }
        return;
    }
    
    DFS(numbers, target, pos+1, sum + numbers[pos]);
    DFS(numbers, target, pos+1, sum - numbers[pos]);
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, target, 0, 0);
    return answer;
}