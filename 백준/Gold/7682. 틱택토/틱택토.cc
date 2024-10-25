#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back
typedef pair<int, int> pii;

bool IsValid(string s) {
    int CircleCnt = count(s.begin(), s.end(), 'O');
    int XCnt = count(s.begin(), s.end(), 'X');

    // X는 O보다 같거나 많아야 하고 차이가 1 이하여야 유효
    if (XCnt < CircleCnt || XCnt > CircleCnt + 1) {
        return false;
    }

    // 승리 조건 판단
    bool XWin = false, OWin = false;
    // 가로 체크
    for (int i = 0; i < 9; i += 3) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            if (s[i] == 'X')
                XWin = true;
            if (s[i] == 'O')
                OWin = true;
        }
    }

    // 세로 체크
    for (int i = 0; i < 3; ++i) {
        if (s[i] == s[i + 3] && s[i] == s[i + 6]) {
            if (s[i] == 'X')
                XWin = true;
            if (s[i] == 'O')
                OWin = true;
        }
    }

    // 대각선 체크
    if (s[0] == s[4] && s[0] == s[8]) {
        if (s[0] == 'X')
            XWin = true;
        if (s[0] == 'O')
            OWin = true;
    }
    if (s[2] == s[4] && s[2] == s[6]) {
        if (s[2] == 'X')
            XWin = true;
        if (s[2] == 'O')
            OWin = true;
    }

    // 두 사람이 동시에 이길 수는 없음
    if (XWin && OWin) {
        return false;
    }

    // X가 이겼다면 X가 O보다 1개 더 많아야 함
    if (XWin && XCnt != CircleCnt + 1) {
        return false;
    }

    // O가 이겼다면 X와 O의 수가 같아야 함
    if (OWin && XCnt != CircleCnt) {
        return false;
    }

    // 승자가 없으면 게임판이 꽉 차있어야 유효
    if (!XWin && !OWin && XCnt + CircleCnt != 9) {
        return false;
    }

    return true;
}

int main() {
    FASTIO

    while (true) {
        string s;
        cin >> s;

        if (s == "end") {
            break;
        }

        if (IsValid(s)) {
            cout << "valid" << endl;
        } else {
            cout << "invalid" << endl;
        }

    }

    return 0;
}