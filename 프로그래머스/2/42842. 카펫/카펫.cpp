#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    ll boardSize = brown + yellow;

    for(int i = 3; i <= sqrt(boardSize); i++){
        if(boardSize % i == 0){
            int j = boardSize / i;
            
            if(brown == (j + i - 2) * 2){
                return {j, i};
            }
        }
    }
    
    return answer;
}