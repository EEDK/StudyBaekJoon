#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target) {
  int answer = 0;

  for (auto it : numbers) {
    if (it == target) {
      answer++;
    }
  }
  return answer;
}

int main() {
  int n;
  cin >> n;
  vector<int> numbers;

  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    numbers.push_back(num);
  }

  int m;
  cin >> m;

  cout << solution(numbers, m) << endl;

  return 0;
}
