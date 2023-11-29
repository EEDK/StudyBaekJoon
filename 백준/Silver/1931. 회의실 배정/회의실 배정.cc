#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<pair<int, int>> meetings;

  for (int i = 0; i < N; ++i) {
    int start, end;
    cin >> start >> end;
    meetings.push_back({end, start});
  }

  sort(meetings.begin(), meetings.end());

  int answer = 1;
  int lastEndTime = meetings[0].first;

  for (int i = 1; i < N; ++i) {
    if (meetings[i].second >= lastEndTime) {
      answer++;
      lastEndTime = meetings[i].first;
    }
  }

  cout << answer << endl;

  return 0;
}
