#include <vector>
long long sum(std::vector<int> &a) {
  long long result = 0;
  for (int it : a) {
    result += it;
  }

  return result;
}
