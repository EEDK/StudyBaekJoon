#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land) {
  int n = land.size();
  vector<vector<int>> dp(n, vector<int>(4, 0));

  for (int i = 0; i < 4; i++) {
    dp[0][i] = land[0][i];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        if (j != k) {
          dp[i][j] = max(dp[i][j], land[i][j] + dp[i - 1][k]);
        }
      }
    }
  }

  return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}