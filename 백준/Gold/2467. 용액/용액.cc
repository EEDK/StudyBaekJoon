#include <bits/stdc++.h>

using namespace std;

void Solution(vector<long long> inputs) {
  int left = 0;
  int right = inputs.size() - 1;
  long long resLiquid = abs(inputs[left] + inputs[right]);

  int leftPos = left;
  int rightPos = right;

  while (left < right) {
    if (abs(inputs[left] + inputs[right]) < resLiquid) {
      leftPos = left;
      rightPos = right;
      resLiquid = abs(inputs[left] + inputs[right]);
    }

    if (inputs[left] + inputs[right] < 0) {
      left++;
    } else {
      right--;
    }
  }
  cout << inputs[leftPos] << " " << inputs[rightPos] << endl;
}

int main() {
  int N;
  cin >> N;

  vector<long long> inputs;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    inputs.push_back(tmp);
  }

  Solution(inputs);

  return 0;
}
