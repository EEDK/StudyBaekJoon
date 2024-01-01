#include <bits/stdc++.h>

using namespace std;

long long solution(int N){
  vector<long long> dp(N + 1, 0);
  dp[1] = 1;
  dp[2] = 3;
  
  for(int i = 3; i <= N; i++){
    dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
  }
  
  return dp[N] ; 
}

int main() {
  int N;
  cin >> N;

  cout << solution(N) << endl;

  return 0;
}
