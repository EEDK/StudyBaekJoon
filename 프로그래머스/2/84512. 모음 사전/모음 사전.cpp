#include <bits/stdc++.h>

using namespace std;

int solution(string word) {
    vector<int> multiplier = {781, 156, 31, 6, 1};
    string vowels = "AEIOU"; 
    int result = 0;

    for (int i = 0; i < word.length(); i++) {
        int index = vowels.find(word[i]);
        result += index * multiplier[i] + 1;
    }

    return result;
}
