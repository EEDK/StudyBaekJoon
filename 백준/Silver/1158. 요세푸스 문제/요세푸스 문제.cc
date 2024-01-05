#include <bits/stdc++.h>

using namespace std;

void Solution(int N, int K){
 queue<int> queue_1;
 for(int i = 1; i <= N; i++){
   queue_1.push(i);
 }
 
 cout << "<";
 while(queue_1.size() > 1){
   for(int i = 0; i < K - 1; i++){
     queue_1.push(queue_1.front());
     queue_1.pop();
   }
   
   cout << queue_1.front() << ", ";
   queue_1.pop();
 }
 
 cout << queue_1.front() << ">";
}

int main() {
//  freopen("input.txt", "r", stdin);
  int N, K;
  cin >> N >> K;

  Solution(N, K);
  
  return 0;
}
