#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int Stair(vector<int> scores) {
  int n = scores.size();
  vector<int> dp(n, 0);

  dp[0] = scores[0];
  dp[1] = max(scores[0] + scores[1], scores[1]);
  dp[2] = max(scores[0] + scores[2], scores[1] + scores[2]);

  for (int i = 3; i < n; i++) {
    dp[i] = max(dp[i - 2] + scores[i], scores[i - 1] + scores[i] + dp[i - 3]);
  }

  return dp[n - 1];
}

int main() {

  int N;
  cin >> N;

  vector<int> scores(N);
  for (int i = 0; i < N; i++) {
    cin >> scores[i];
  }

  int maxScore = Stair(scores);
  cout << maxScore << endl;

  return 0;
}