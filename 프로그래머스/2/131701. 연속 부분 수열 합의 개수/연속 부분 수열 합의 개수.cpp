#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int N = elements.size();
    
    unordered_set<int> set;
    
    vector<int> CircleElements(2*N, 0);
    
    for(int i = 0; i < 2*N; i++){
        CircleElements[i] = elements[i % N] ;
    }
    
    for (int length = 1; length <= N; length++) {
        for (int start = 0; start < N; start++) {
            int sum = 0;
            for (int k = 0; k < length; k++) {
                sum += CircleElements[start + k];
            }
            set.insert(sum); 
        }
    }
    
    return set.size();
}