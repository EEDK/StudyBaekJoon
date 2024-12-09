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

int N;
vvi Graph;

int cntMinus;
int cntZero;
int cntOne;

void NumCnt(int startX, int endX, int startY, int endY) {
  int Target = Graph[startX][startY];
  int newSize = (endX - startX) / 3;

  for (int i = startX; i < endX; ++i) {
    for (int j = startY; j < endY; ++j) {
      if (Target != Graph[i][j]) {
        for (int x = 0; x < 3; ++x) {
          for (int y = 0; y < 3; ++y) {
            NumCnt(startX + x * newSize, startX + (x + 1) * newSize,
                   startY + y * newSize, startY + (y + 1) * newSize);
          }
        }
        return;
      }
    }
  }

  if (Target == -1) {
    cntMinus++;
  } else if (Target == 0) {
    cntZero++;
  } else if (Target == 1) {
    cntOne++;
  }
}

int main() {
  FASTIO

  cin >> N;

  Graph.resize(N, vi(N, 0));

  FOR(i, N) {
    FOR(j, N) { cin >> Graph[i][j]; }
  }

  cntMinus = 0;
  cntZero = 0;
  cntOne = 0;

  NumCnt(0, N, 0, N);

  cout << cntMinus << endl;
  cout << cntZero << endl;
  cout << cntOne << endl;

  return 0;
}
