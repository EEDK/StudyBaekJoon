#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int N, int K, vector<int> &weights, vector<int> &values) {
  vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      if (weights[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
      }
    }
  }

  return dp[N][K];
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> weights(N);
  vector<int> values(N);

  for (int i = 0; i < N; i++) {
    cin >> weights[i] >> values[i];
  }

  int result = knapsack(N, K, weights, values);
  cout << result << endl;

  return 0;
}
