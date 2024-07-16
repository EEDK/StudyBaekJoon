#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {    
    // Pattern A-> 1, 2, 3, 4, 5, 반복 
    // Pattern B-> 2, 1, 2, 3, 2, 4, 2, 5 반복
    // Pattern C-> 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 반복
    
    vector<int> APattern = {1, 2, 3, 4, 5};
    vector<int> BPattern = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> CPattern = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int answerA = 0;
    int answerB = 0;
    int answerC = 0;
    int maxCorrectCnt = 0;
    
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == APattern[i % 5]){
            answerA++;
        }
        
        if(answers[i] == BPattern[i % 8]){
            answerB++;
        }
        
        if(answers[i] == CPattern[i % 10]){
            answerC++;
        }
    }
    
    
    
    vector<int> temp{answerA, answerB, answerC};
    int maxCnt = *max_element(temp.begin(), temp.end());
  
    vector<int> answer;
    if(maxCnt == answerA){
        answer.push_back(1);
    }
    if(maxCnt == answerB){
        answer.push_back(2);
    }
    if(maxCnt == answerC){
        answer.push_back(3);
    }
    
    return answer;
}