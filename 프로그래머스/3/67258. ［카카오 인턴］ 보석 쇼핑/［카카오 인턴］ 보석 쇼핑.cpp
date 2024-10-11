#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> gemTypes(gems.begin(), gems.end());  
    int totalGemTypes = gemTypes.size();  
    
    unordered_map<string, int> gemCount;  
    int start = 0, end = 0, minLength = gems.size() + 1;
    vector<int> answer(2);

    while (end < gems.size()) {
        gemCount[gems[end]]++;
        end++;

        while (gemCount.size() == totalGemTypes) {
            if (end - start < minLength) {
                minLength = end - start;
                answer[0] = start + 1;  
                answer[1] = end;        
            }

            gemCount[gems[start]]--;
            if (gemCount[gems[start]] == 0) {
                gemCount.erase(gems[start]); 
            }
            start++;
        }
    }

    return answer;
}