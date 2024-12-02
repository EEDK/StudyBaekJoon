#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
  string answer = "";

  vector<string> NumStr;

  for (auto number : numbers) {
    NumStr.push_back(to_string(number));
  }

  sort(NumStr.begin(), NumStr.end(), [](const string& a, const string& b) {
    return a + b > b + a;
  });

  if (NumStr[0] == "0") {
    return "0";
  }

  for (auto str : NumStr) {
    answer += str;
  }

  return answer;
}