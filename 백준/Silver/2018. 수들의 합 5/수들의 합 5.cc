#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    int startIdx = 1;
    int endIdx = 1;
    int Sum = 1;

    int cnt = 1;

    while (endIdx != N) {
        if (Sum == N) {
            cnt++;
            endIdx++;
            Sum += endIdx;
        } else if (Sum > N) {
            Sum -= startIdx;
            startIdx++;
        } else {
            endIdx++;
            Sum += endIdx;
        }
    }

    cout << cnt << endl;

    return 0;
}
