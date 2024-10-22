#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
int N;

vector<int> CalcSoo(int nextNum) {

    vector<int> Result;

    Result.push_back(N);
    Result.push_back(nextNum);

    while (true) {
        int a = Result[Result.size() - 2];
        int b = Result[Result.size() - 1];

        int diff = a - b;

        if (diff < 0) {
            break;
        }

        Result.push_back(diff);
    }

    return Result;
}

int main() {
    FASTIO

    cin >> N;

    int MaxSize = 0;
    vector<int> Result;

    for (int i = N; i > 0; i--) {
        vector<int> TempResult = CalcSoo(i);
        if (MaxSize < TempResult.size()) {
            MaxSize = TempResult.size();
            Result = TempResult;
        }
    }

    cout << MaxSize << endl;
    for (const auto& item : Result) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}