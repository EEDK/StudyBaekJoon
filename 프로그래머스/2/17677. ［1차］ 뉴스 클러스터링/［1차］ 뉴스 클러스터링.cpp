#include <bits/stdc++.h>

using namespace std;

vector<string> createMultiset(const string& str) {
    vector<string> multiset;
    for (int i = 0; i < str.length() - 1; ++i) {
        if (isalpha(str[i]) && isalpha(str[i + 1])) {
            string pair = "";
            pair += tolower(str[i]);
            pair += tolower(str[i + 1]);
            multiset.push_back(pair);
        }
    }
    return multiset;
}

int intersection(const unordered_map<string, int>& map1, const unordered_map<string, int>& map2) {
    int inter = 0;
    for (const auto& elem : map1) {
        if (map2.find(elem.first) != map2.end()) {
            inter += min(elem.second, map2.at(elem.first));
        }
    }
    return inter;
}

int unionSet(const unordered_map<string, int>& map1, const unordered_map<string, int>& map2) {
    int uni = 0;
    unordered_map<string, int> unionMap = map1;
    for (const auto& elem : map2) {
        unionMap[elem.first] = max(unionMap[elem.first], elem.second); 
    }
    for (const auto& elem : unionMap) {
        uni += elem.second;
    }
    return uni;
}

int solution(string str1, string str2) {
    vector<string> A = createMultiset(str1);
    vector<string> B = createMultiset(str2);
    
    unordered_map<string, int> mapA, mapB;
    for (const auto& elem : A) mapA[elem]++;
    for (const auto& elem : B) mapB[elem]++;
    
    int inter = intersection(mapA, mapB);
    int uni = unionSet(mapA, mapB);
    
    if (uni == 0) return 65536;
    
    double jaccard = (double)inter / uni;
    return floor(jaccard * 65536);
}
