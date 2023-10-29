#include <vector>
#include <array>
#include <iostream>

using namespace std;

int solution(int Price) {
  int answer = 0;
  int leftPrice = 1000 - Price;

  while (leftPrice > 0) {
    if (leftPrice >= 500) {
      leftPrice -= 500;
      answer++;
      continue;
    }
    if (leftPrice >= 100) {
      leftPrice -= 100;
      answer++;
      continue;
    }
    if (leftPrice >= 50) {
      leftPrice -= 50;
      answer++;
      continue;
    }
    if (leftPrice >= 10) {
      leftPrice -= 10;
      answer++;
      continue;
    }
    if (leftPrice >= 5) {
      leftPrice -= 5;
      answer++;
      continue;
    }
    if (leftPrice >= 1) {
      leftPrice -= 1;
      answer++;
      continue;
    }
  }

  return answer;

}

int main() {
  int N;

  cin >> N;

  cout << solution(N) << endl;

  return 0;
}