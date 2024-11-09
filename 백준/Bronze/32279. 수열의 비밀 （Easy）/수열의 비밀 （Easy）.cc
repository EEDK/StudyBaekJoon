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
typedef vector<vector<int>> vvi;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int n, p, q, r, s, a1;

int main()
{
    FASTIO

    vi DP(21, 0);

    cin >> n;
    cin >> p >> q >> r >> s;
    cin >> a1;

    DP[1] = a1;

    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            DP[i] = DP[i / 2] * p + q;
        }
        else
        {
            DP[i] = DP[i / 2] * r + s;
        }
    }
    cout << accumulate(DP.begin(), DP.end(), 0) << endl;

    return 0;
}
