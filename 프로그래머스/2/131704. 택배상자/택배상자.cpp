#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
  int answer = 0;
  int idx = 0;
  stack<int> Container;

  for (int i = 1; i < order.size() + 1; i++) {
    if (order[idx] != i) {
      Container.push(i);
    } else {
      idx += 1;
      answer++;
    }

    while (!Container.empty() && Container.top() == order[idx]) {
      idx += 1;
      answer++;
      Container.pop();
    }
  }

  return answer;
}
