#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int MakeOne(int n) {
  int answer = 0;

  vector<int> dp(n + 1, 0);

  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;

    if (i % 2 == 0) {
      dp[i] = min(dp[i], dp[i / 2] + 1);
    }

    if (i % 3 == 0) {
      dp[i] = min(dp[i], dp[i / 3] + 1);
    }
  }

  return dp[n];
}

int main() {

  int N;
  cin >> N;

  cout << MakeOne(N) << endl;

  return 0;
}