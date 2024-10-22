#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int n, x;

int main() {
    FASTIO

    cin >> n;
    vector<int> Inputs(n, 0);
    FOR(i, n) {
        cin >> Inputs[i];
    }

    cin >> x;

    sort(Inputs.begin(), Inputs.end());

    int left = 0;
    int right = n - 1;

    int answer = 0;
    while (left < right) {
        int result = Inputs[left] + Inputs[right];
        if (result == x) {
            answer++;
            left++;
            right--;
        } else if (result > x) {
            right--;
        } else {
            left++;
        }
    }

    cout << answer << endl;

    return 0;
}