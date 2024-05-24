#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    
    cin >> N;
    vector<int> Inputs(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> Inputs[i];
    }
    
    vector<int> Answer(N, 0);
    
    stack<int> NGE;
    NGE.push(0);
    
    for(int i = 1; i < N; i++){
        while(!NGE.empty() && Inputs[NGE.top()] < Inputs[i]){
            Answer[NGE.top()] = Inputs[i];
            NGE.pop();
        }
        NGE.push(i);
    }
    
    while(!NGE.empty()){
        Answer[NGE.top()] = -1;
        NGE.pop();
    }
    
    for(auto val : Answer){
        cout << val << " ";
    }
    
    return 0;
}
