#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int RelateSum(vector<int> inputs) {
  int N = inputs.size();

  vector<int> dp(N, 0);
  dp[0] = inputs[0];

  for (int i = 1; i < N; i++) {
    dp[i] = max(dp[i - 1] + inputs[i], inputs[i]);
  }

  return *max_element(dp.begin(), dp.end());
}

int main() {
  int n;
  cin >> n;

  vector<int> inputs(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> inputs[i];
  }

  cout << RelateSum(inputs) << endl;

  return 0;
}