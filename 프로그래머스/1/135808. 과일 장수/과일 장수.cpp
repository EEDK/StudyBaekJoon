#include <bits/stdc++.h>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    int n = score.size();
    int boxCnt = n / m;
    int add = n - m * boxCnt;
    
    int Pos = add;
    
    sort(score.begin(), score.end());

    for(Pos; Pos < n; Pos = Pos + m){
        int p = score[Pos];
        answer += p * m;
    }
        
    
    return answer;
}