#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  int Idx = 0;
  int size = progresses.size();

  while (Idx < size) {
    for (int i = Idx; i < size; i++) {
      progresses[i] += speeds[i];
    }

    if (progresses[Idx] >= 100) {
      int temp = 1;
      Idx++;

      while (Idx < size && progresses[Idx] >= 100) {
        temp++;
        Idx++;
      }

      answer.push_back(temp);
    }
  }

  return answer;
}
