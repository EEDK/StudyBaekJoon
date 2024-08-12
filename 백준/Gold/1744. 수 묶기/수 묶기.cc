#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<int> PlusPq;
    priority_queue<int, vector<int>, greater<int>> MinusPq;

    int one = 0;
    int zero = 0;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        if (tmp > 1) {
            PlusPq.push(tmp);
        } else if (tmp == 1) {
            one++;
        } else if (tmp == 0) {
            zero++;
        } else {
            MinusPq.push(tmp);
        }
    }

    int answer = 0;

    while (PlusPq.size() > 1) {
        int first = PlusPq.top();
        PlusPq.pop();
        int second = PlusPq.top();
        PlusPq.pop();
        answer += first * second;
    }

    if (!PlusPq.empty()) {
        answer += PlusPq.top();
        PlusPq.pop();
    }

    while (MinusPq.size() > 1) {
        int first = MinusPq.top();
        MinusPq.pop();
        int second = MinusPq.top();
        MinusPq.pop();
        answer += first * second;
    }

    if (!MinusPq.empty()) {
        if (zero == 0) {
            answer += MinusPq.top();
            MinusPq.pop();
        }
    }
    
    answer += one;
    
    cout << answer << endl;

    return 0;
}
