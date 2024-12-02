#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> PatternA = {1,2,3,4,5};
    vector<int> PatternB = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> PatternC = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int cntA = 0;
    int cntB = 0;
    int cntC = 0;
    
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == PatternA[i % PatternA.size()]){
            cntA++;
        }
        if(answers[i] == PatternB[i % PatternB.size()]){
            cntB++;
        }
        if(answers[i] == PatternC[i % PatternC.size()]){
            cntC++;
        }
    }
    
    int maxCnt = max(max(cntA, cntB), cntC);
    
    if(cntA == maxCnt){
        answer.push_back(1);
    }
    if(cntB == maxCnt){
        answer.push_back(2);
    }
    if(cntC == maxCnt){
        answer.push_back(3);
    }
    return answer;
}