#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LIS(vector<int> inputs) {
  int n = inputs.size();
  vector<int> dp(n, 1);

  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      if (inputs[j] > inputs[i]) {
        dp[i] = max(dp[i], 1 + dp[j]);
      }
    }
  }

  return *max_element(dp.begin(), dp.end());
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

  int answer = LIS(inputs);
  cout << answer << endl;

  return 0;
}
