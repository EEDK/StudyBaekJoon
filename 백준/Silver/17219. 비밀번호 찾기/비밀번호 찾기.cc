#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N, M;
  cin >> N >> M;
  
  unordered_map<string, string> password;
  vector<string> target;
  
  for(int i = 0; i < N; i++){
    string url, passwd;
    
    cin >> url >> passwd;
    password.insert(make_pair(url, passwd));
  }
  
  for(int i = 0; i < M; i++){
    string targetUrl;
    cin >> targetUrl;
    
    cout << password[targetUrl] << "\n";
  }
  
  return 0;
}
