#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  vector<int> inputs;

  for (int i = 0; i < 3; i++) {
    int n;
    cin >> n;
    inputs.push_back(n);
  }

  sort(inputs.begin(), inputs.end());

  cout << inputs[1] << endl;

  return 0;
}