#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

long long min(int a, int b) {
  return a > b ? b : a;
}

long long DistanceOfRGB(vector<vector<int>> maps) {
  int n = maps.size();

  vector<vector<long long>> dp(n, vector<long long>(n, INT_MAX));
  for (int i = 0; i < 3; i++) {
    dp[0][i] = maps[0][i];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      switch (j) {
        case 0:dp[i][0] = min(maps[i][j] + dp[i - 1][1], maps[i][j] + dp[i - 1][2]);
          break;
        case 1:dp[i][1] = min(maps[i][j] + dp[i - 1][0], maps[i][j] + dp[i - 1][2]);
          break;
        default:dp[i][2] = min(maps[i][j] + dp[i - 1][0], maps[i][j] + dp[i - 1][1]);
          break;
      }
    }
  }

  return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> inputs;
  for (int i = 0; i < n; i++) {
    vector<int> temp;
    for (int j = 0; j < 3; j++) {
      int t;
      cin >> t;

      temp.push_back(t);
    }
    inputs.push_back(temp);
  }

  cout << DistanceOfRGB(inputs) << endl;

  return 0;
}