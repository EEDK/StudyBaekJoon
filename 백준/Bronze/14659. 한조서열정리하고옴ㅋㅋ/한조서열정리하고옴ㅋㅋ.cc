#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int Solution(vector<int> mountains) {
  int N = mountains.size();
  vector<int> score(N, 0);

  for (int i = 0; i < N; i++) {
    int Height = mountains[i];
    int cnt = 0;
    for (int j = i + 1; j < N; j++) {
      if (Height < mountains[j]) {
        break;
      }
      cnt++;
    }
    score[i] = cnt;
  }

  return *max_element(score.begin(), score.end());
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

  cout << Solution(inputs) << endl;

  return 0;
}