#include <bits/stdc++.h>

using namespace std;

bool bIsOver(vector<long long> inputs, long long split, long long targetCnt);

long long Solution(vector<long long> inputs, long long TargetSize) {
  sort(inputs.begin(), inputs.end(), greater<int>());

  long long left = 1;
  long long right = inputs[0]; 
  long long result = 0;

  while (left <= right) {
    long long mid = left + (right - left) / 2;

    if (bIsOver(inputs, mid, TargetSize)) {
      result = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return result;
}

bool bIsOver(vector<long long> inputs, long long split, long long targetCnt){
  long long sum = 0;
  for(long long input: inputs){
    sum += (input / split);
  }
  
  return sum >= targetCnt;
}

int main() {  
  long long n, TargetSize;
  cin >> n >> TargetSize;
 
  vector<long long> inputs;
  for(long long i = 0; i < n; i++){
    long long tmp;
    cin >> tmp;
    
    inputs.push_back(tmp);
  }

  cout << Solution(inputs, TargetSize) << endl;
  
  return 0;
}
