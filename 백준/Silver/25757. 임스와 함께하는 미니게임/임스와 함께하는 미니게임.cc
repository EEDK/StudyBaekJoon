#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, cnt;
    string Game;
    cin >> N >> Game;

    set<string> user;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;

        user.insert(tmp);
    }

    if (Game == "Y") {
        cnt = 1;
    } else if (Game == "F") {
        cnt = 2;
    } else {
        cnt = 3;
    }

    cout << user.size() / cnt << endl;

    return 0;
}
