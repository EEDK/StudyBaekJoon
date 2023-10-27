#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;

  cin >> n;

  vector<int> answer;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;

    if (max_heap.empty() || m <= max_heap.top()) {
      max_heap.push(m);
    } else {
      min_heap.push(m);
    }

    if (max_heap.size() > min_heap.size() + 1) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    } else if (min_heap.size() > max_heap.size()) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }

    int middle_element = max_heap.top();
    answer.push_back(middle_element);
  }

  for (auto item : answer) {
    cout << item << "\n";
  }

  return 0;
}
