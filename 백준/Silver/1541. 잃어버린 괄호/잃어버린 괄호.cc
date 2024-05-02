#include <bits/stdc++.h>

using namespace std;
int main() {
    string expression;
    getline(cin, expression);

    stringstream ss(expression);
    string token;

    int result = 0;
    bool first = true;

    while (getline(ss, token, '-')) {
        stringstream ss_token(token);
        string sub_token;

        int sum = 0;
        while (getline(ss_token, sub_token, '+')) {
            sum += stoi(sub_token);
        }
        if (first) {
            result += sum;
            first = false;
        } else {
            result -= sum;
        }
    }

    cout << result << endl;

    return 0;
}
