#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF (~0U >> 2)
#define PB push_back
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int N;

ll Solve()
{
    vector<ll> DP(18, 0);

    DP[10] = 6;

    for (int i = 11; i <= 17; i++)
    {
        DP[i] = DP[i - 1] * i;
    }

    return DP[N];
}

int main()
{
    FASTIO

    cin >> N;

    cout << Solve() << endl;

    return 0;
}
