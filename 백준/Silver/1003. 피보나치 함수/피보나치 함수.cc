#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

typedef long long ll;

int main()
{
    FASTIO;

    vector<ll> DP(41, 0);

    DP[1] = 1;
    DP[2] = 1;
    for (int i = 3; i < 41; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        if (N == 0)
        {
            cout << 1 << " " << 0 << endl;
        }
        else
        {
            cout << DP[N - 1] << " " << DP[N] << endl;
        }
    }


    return 0;
}
