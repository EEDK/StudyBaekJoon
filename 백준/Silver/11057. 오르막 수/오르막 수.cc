#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF (~0U >> 2)
#define PB push_back
#define MOD 10007

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int N;

ll Solve()
{
    vector<vector<ll>> DP(N + 1, vector<ll>(10, 0));

    for (int i = 0; i < 10; i++)
    {
        DP[1][i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                DP[i][j] += DP[i - 1][k];
            }
            DP[i][j] %= MOD;
        }
    }
    return accumulate(DP[N].begin(), DP[N].end(), 0) % MOD;
}

int main()
{
    FASTIO
    cin >> N;

    cout << Solve() << endl;

    return 0;
}
