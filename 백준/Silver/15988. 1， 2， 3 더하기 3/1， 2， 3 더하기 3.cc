#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;

int main()
{
    FASTIO

    int t;
    cin >> t;

    vector<ll> DP(1000001, 0);
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;

    for (int i = 4; i < 1000001; i++)
    {
        DP[i] = (DP[i - 3] + DP[i - 2] + DP[i - 1]) % 1000000009;
    }

    while (t--)
    {
        int a;
        cin >> a;

        cout << DP[a] << endl;
    }

    return 0;
}
