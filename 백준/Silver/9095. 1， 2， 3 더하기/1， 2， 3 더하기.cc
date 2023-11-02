#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

void Solution(int num) {
  vector<int> dp(num + 1, 0);
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for (int i = 4; i < num + 1; i++) {
    dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
  }

  cout << dp[num] << endl;
}

int main() {

//  freopen("../input.txt", "r", stdin);
  int N;
  cin >> N;

  vector<int> inputs;
  for (int i = 0; i < N; i++) {
    int c;
    cin >> c;
    inputs.push_back(c);
  }

  for (int input : inputs) {
    Solution(input);
  }

  return 0;
}