#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
  int answer = 0;
  priority_queue<int, vector<int>, greater<int> > pq;
  for (int item : scoville) {
    pq.push(item);
  }

  while (pq.top() < K && pq.size() >= 2) {
    int first = pq.top();
    pq.pop();
    int second = pq.top();
    pq.pop();

    int result = first + (second * 2);
    pq.push(result);
    answer++;
  }

  if (pq.top() < K) {
    answer = -1;
  }

  return answer;
}