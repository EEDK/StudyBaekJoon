#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF (~0U >> 2)
#define PB push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, B, C;
vi A;

int main() {
    FASTIO;

    cin >> N;
    A.resize(N);

    FOR(i, N) {
        cin >> A[i];
    }

    cin >> B >> C;

    ll answer = 0;
    FOR(i, N) {
        A[i] -= B;
        answer++;

        if (A[i] > 0) {
            answer += (A[i] + C - 1) / C;
        }
    }

    cout << answer << endl;

    return 0;
}