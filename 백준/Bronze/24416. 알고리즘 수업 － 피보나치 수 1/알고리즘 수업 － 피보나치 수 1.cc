#include <vector>
#include <iostream>

using namespace std;

void fibonacciDP(int n) {
  vector<long long> f(n + 1);

  int cnt = 0;
  f[0] = 0;
  f[1] = 1;
  for (int i = 2; i < n; i++) {
    f[i] = f[i - 1] + f[i - 2];
    cnt++;
  }

  cout << f[n - 1] + f[n - 2] << " " << cnt;

}

int main() {
  int n;
  cin >> n;
  
  fibonacciDP(n);
}