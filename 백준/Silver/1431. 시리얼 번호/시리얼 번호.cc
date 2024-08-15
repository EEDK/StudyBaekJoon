#include <bits/stdc++.h>

using namespace std;

int sumOfDigits(const string &s) {
  int sum = 0;
  for (char ch : s) {
    if (isdigit(ch)) {
      sum += ch - '0'; 
    }
  }
  return sum;
}

bool comp(const string &a, const string &b) {
  if (a.length() != b.length()) {
    return a.length() < b.length();
  }

  int sumA = sumOfDigits(a);
  int sumB = sumOfDigits(b);
  if (sumA != sumB) {
    return sumA < sumB;
  }

  return a < b;
}

int main() {
  int N;
  cin >> N;
  vector<string> inputs;

  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    inputs.push_back(str);
  }

  sort(inputs.begin(), inputs.end(), comp);

  for (string input : inputs) {
    cout << input << endl;
  }

  return 0;
}