#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> inputs, int S){
    int start = 0, end = 0;
    int min_length = INT_MAX; 
    int current_sum = 0;

    while (end < inputs.size()) {
        current_sum += inputs[end];
        end++;

        while (current_sum >= S) {
            min_length = min(min_length, end - start);
            current_sum -= inputs[start];
            start++;
        }
    }

    if (min_length == INT_MAX){
        return 0;
    } else {
        return  min_length;
    } 
    
}

int main() {
//  freopen("input.txt", "r", stdin);
  
  int N, S;
  cin >> N >> S;

  vector<int> inputs;
  for(int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    inputs.push_back(tmp);
  }
  
  cout << solution(inputs, S) << endl;

  return 0;
}
