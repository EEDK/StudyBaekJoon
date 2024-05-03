#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> Stack;

    for (int i = 0; i < n; i++) {
        string str;

        cin >> str;

        if (str == "push") {
            int num;
            cin >> num;
            Stack.push(num);
        } else if (str == "pop") {
            if (Stack.empty()) {
                cout << -1 << endl;
            } else {
                cout << Stack.top() << endl;
                Stack.pop();
            }
        } else if (str == "size") {
            cout << Stack.size() << endl;
        } else if (str == "empty") {
            if (Stack.empty()) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (str == "top") {
            if (Stack.empty()) {
                cout << -1 << endl;
            } else {
                cout << Stack.top() << endl;
            }
        }
    }

    return 0;
}
