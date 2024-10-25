#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string N;

int main() {
    FASTIO;

    cin >> N;

    sort(N.begin(), N.end(), greater<char>());

    if (N.back() != '0') {
        cout << -1 << endl;
        return 0;
    }

    int sum = 0;
    for (char c : N) sum += (c - '0');

    if (sum % 3 == 0) {
        cout << N << endl;
    } else {
        cout << -1 << endl;
    }


    return 0;
}