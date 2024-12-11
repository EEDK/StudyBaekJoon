#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FASTIO             \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define INF (~0U >> 2)
#define PB push_back
#define MOD 10007

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

string s1;
string s2;

int Solve() {
  int n = s1.size();
  int m = s2.size();

  vvi DP(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        DP[i][j] = DP[i - 1][j - 1] + 1;
      } else {
        DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
      }
    }
  }

  return DP[n][m];
}

int main() {
  FASTIO

  cin >> s1 >> s2;

  cout << Solve() << endl;

  return 0;
}
