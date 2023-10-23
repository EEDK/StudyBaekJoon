#include <vector>

using namespace std;

vector<long long> dp(21, -1);

long long factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  if (dp[n] != -1) {
    return dp[n];
  }

  dp[n] = n * factorial(n - 1);

  return dp[n];
}

#include <iostream>

int main() {

  int n;
  cin >> n;

  cout << factorial(n) << endl;

  return 0;
}
