#include <bits/stdc++.h>

using namespace std;

int L, C;
vector<char> chars;
vector<char> password;
string vowels = "aeiou";

bool isVowel(char ch) {
    return vowels.find(ch) != string::npos;
}

void backtrack(int idx, int vowelCount, int consonantCount) {
    if (password.size() == L) {
        if (vowelCount >= 1 && consonantCount >= 2) {
            for (char ch : password) {
                cout << ch;
            }
            cout << '\n';
        }
        return;
    }

    for (int i = idx; i < C; ++i) {
        password.push_back(chars[i]);
        if (isVowel(chars[i])) {
            backtrack(i + 1, vowelCount + 1, consonantCount);
        } else {
            backtrack(i + 1, vowelCount, consonantCount + 1);
        }
        password.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;
    chars.resize(C);

    for (int i = 0; i < C; ++i) {
        cin >> chars[i];
    }

    sort(chars.begin(), chars.end());

    backtrack(0, 0, 0);


    return 0;
}
