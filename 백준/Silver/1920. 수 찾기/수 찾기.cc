#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A, int target) {
  if (binary_search(A.begin(), A.end(), target))
    return 1;

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> A;
  A.reserve(n);

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    A.push_back(input);
  }

  sort(A.begin(), A.end());

  int m;
  cin >> m;
  vector<int> target;
  target.reserve(m);

  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    target.push_back(num);
  }

  for (int it : target) {
    int answer = solution(A, it);
    cout << answer << '\n';
  }

  return 0;
}
