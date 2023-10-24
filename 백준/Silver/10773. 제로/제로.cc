#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(vector<int> inputs) {
  stack<int> stack_1;
  for (auto it : inputs) {
    if (it == 0 && !stack_1.empty()) {
      stack_1.pop();
    } else {
      stack_1.push(it);
    }
  }

  int answer = 0;
  while (!stack_1.empty()) {
    answer += stack_1.top();
    stack_1.pop();
  }

  return answer;
}

int main() {
  int n;
  cin >> n;

  vector<int> inputs{};
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    inputs.push_back(m);
  }

  int answer = solution(inputs);
  cout << answer << endl;

  return 0;
}
