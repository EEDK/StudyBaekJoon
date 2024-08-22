#include <bits/stdc++.h>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    vector<int> Tree;
    
    for(int i = 0; i < n; i++){
        Tree.push_back(i+1);
    }
    if(a % 2 != 0){
        a++;
    }
    if(b % 2 != 0){
        b++;
    }
    answer++;
    
    while(a != b){
        a /= 2;
        b /= 2;
        if(a % 2 != 0){
            a++;
        }
        if(b % 2 != 0){
            b++;
        }
    
        answer++;
    }

    return answer;
}