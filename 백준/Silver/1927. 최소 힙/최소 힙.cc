#include <bits/stdc++.h>

using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  priority_queue<int, vector<int>, greater<int>> q;
  vector<int> answer;

  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;

    if (tmp == 0) {
      if (q.empty()) {
        answer.push_back(0);
      } else {
        answer.push_back(q.top());
        q.pop();
      }
    } else {
      q.push(tmp);
    }
  }

  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << "\n";
  }

  return 0;
}
