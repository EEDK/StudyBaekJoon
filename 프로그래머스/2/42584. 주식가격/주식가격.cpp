#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
  vector<int> answer;

  for (int i = 0; i < prices.size(); i++) {
    answer.push_back(0);
  }

  for (int i = 0; i < prices.size() - 1; i++) {
    int nowPrice = prices[i];
    int time = 1;
    for (int j = i + 1; j < prices.size() - 1; j++) {
      if (nowPrice <= prices[j])
        time += 1;
      else
        break;
    }

    answer[i] = time;
  }

  return answer;
}