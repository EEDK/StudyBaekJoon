#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int LSS(vector<int> inputs) {
  int N = inputs.size();
  vector<int> dp(N, 1);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (inputs[i] < inputs[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
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

  cout << LSS(inputs) << endl;

  return 0;
}