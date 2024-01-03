#include <bits/stdc++.h>

using namespace std;

int Solution(int N){
  int answer = 0;
  
  vector<int> dp(N+1, 0);
  dp[1] = 1;
  dp[2] = 2;
  
  for(int i = 3; i <= N; i++){
    dp[i] = (dp[i-2] + dp[i-1]) % 10007;
  }
  
  return dp[N];
}

int main() {
  int N;
  cin >> N;

  cout << Solution(N) << endl;

  return 0;
}
