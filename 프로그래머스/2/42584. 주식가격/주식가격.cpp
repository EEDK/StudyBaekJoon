#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
  vector<int> answer(prices.size(), 0);

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