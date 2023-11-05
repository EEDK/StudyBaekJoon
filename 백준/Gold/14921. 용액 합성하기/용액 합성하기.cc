#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int AdjZeroValueSum(vector<int> inputs) {
  int left = 0;
  int right = inputs.size() - 1;
  int closestSum = INT_MAX;

  while (left < right) {
    int sum = inputs[left] + inputs[right];

    if (abs(sum) < abs(closestSum)) {
      closestSum = sum;
    }

    if (sum < 0) {
      left++;
    } else {
      right--;
    }
  }

  return closestSum;

}

int main() {
//  freopen("../input.txt", "r", stdin);
  int n;
  cin >> n;

  vector<int> inputs(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> inputs[i];
  }

  cout << AdjZeroValueSum(inputs) << endl;

  return 0;
}