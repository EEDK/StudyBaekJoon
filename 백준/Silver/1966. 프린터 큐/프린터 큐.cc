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

int T;

int Solve(vi Inputs, int M) {
  int cnt = 0;

  priority_queue<int> SortedQueue(Inputs.begin(), Inputs.end());

  queue<pii> Queue;
  FOR(i, Inputs.size()) { Queue.push({Inputs[i], i}); }

  while (!Queue.empty()) {
    int priority = Queue.front().first;
    int order = Queue.front().second;
    Queue.pop();

    if (priority == SortedQueue.top()) {
      cnt++;
      SortedQueue.pop();

      if (order == M) {
        return cnt;
      }
    } else {
      Queue.push({priority, order});
    }
  }

  return cnt;
}

int main() {
  FASTIO

  cin >> T;

  while (T--) {
    int N, M;
    cin >> N >> M;
    vi Inputs(N);

    FOR(i, N) { cin >> Inputs[i]; }

    cout << Solve(Inputs, M) << endl;
  }

  return 0;
}
