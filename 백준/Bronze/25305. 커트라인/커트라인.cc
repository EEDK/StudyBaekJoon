#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int CutLine(vector<int> scores, int k) {
  sort(scores.begin(), scores.end(), greater<int>());

  return scores[k - 1];
}

int main() {

  int N, k;
  cin >> N >> k;

  vector<int> scores;
  for (int i = 0; i < N; i++) {
    int c;
    cin >> c;
    scores.push_back(c);
  }

  cout << CutLine(scores, k) << endl;

  return 0;
}