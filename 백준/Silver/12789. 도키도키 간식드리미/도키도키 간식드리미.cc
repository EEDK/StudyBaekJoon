#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool solution(vector<int> list) {
  stack<int> stack_1;
  int expected = 1;

  for (int i = 0; i < list.size(); i++) {
    if (list[i] == expected) {
      expected++;
    } else {
      while (!stack_1.empty() && stack_1.top() == expected) {
        stack_1.pop();
        expected++;
      }
      stack_1.push(list[i]);
    }
  }

  while (!stack_1.empty() && stack_1.top() == expected) {
    stack_1.pop();
    expected++;
  }

  return stack_1.empty();
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> numbers;

  for (int i = 0; i < n; ++i) {
    int num;
    std::cin >> num;
    numbers.push_back(num);
  }

  if (solution(numbers)) {
    cout << "Nice" << endl;
  } else {
    cout << "Sad" << endl;
  }

  return 0;
}
