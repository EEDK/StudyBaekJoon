#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> coin_values(n);

  for (int i = 0; i < n; i++) {
    cin >> coin_values[i];
  }

  vector<long long> dp(k + 1, 0);
  dp[0] = 1;

  for (int coin : coin_values) {
    for (int i = coin; i <= k; i++) {
      dp[i] += dp[i - coin];
    }
  }

  cout << dp[k] << endl;

  return 0;
}
