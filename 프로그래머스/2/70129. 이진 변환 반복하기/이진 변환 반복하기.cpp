#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    int trans = 0;
    int deletedZero = 0;
    
    while(s != "1"){
        trans++;
        
        deletedZero += count(s.begin(), s.end(), '0');
        
        int oneCnt = count(s.begin(), s.end(), '1');
        
        s = bitset<32>(oneCnt).to_string();
        s = s.substr(s.find('1'));
    }
    
    answer[0] = trans;
    answer[1] = deletedZero;
    
    return answer;
}