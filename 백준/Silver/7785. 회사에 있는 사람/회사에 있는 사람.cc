#include <bits/stdc++.h>

using namespace std;

int main(){

  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  map<string, string, greater<>> inputs;
  int n; 
  cin >> n;
 
  for(int i = 0; i<n; i++){
    string name, state;

    cin >> name >> state;
    inputs[name] = state;
  }

  for(auto input : inputs){
    if(input.second == "enter"){
      cout << input.first << "\n";
    }
  }

  return 0;
}
