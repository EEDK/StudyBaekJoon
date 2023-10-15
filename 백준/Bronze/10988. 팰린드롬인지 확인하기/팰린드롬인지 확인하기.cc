#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool solution(string str) {
  bool answer = false;

  string reverseStr = str;
  reverse(reverseStr.begin(), reverseStr.end());

  if (reverseStr == str) {
    return true;
  } else {
    return false;
  }
}

int main() {
  string N;
  cin >> N;

  bool result = solution(N);
  cout << result << endl;

  return 0;

}