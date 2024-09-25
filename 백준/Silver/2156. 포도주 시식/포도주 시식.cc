#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> Wines;
vector<ll> DP(10001, 0);

ll N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    Wines.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> Wines[i];
    }

    DP[0] = Wines[0];
    DP[1] = Wines[0] + Wines[1];

    if (N > 2)
    {
        DP[2] = max(max(DP[1], DP[0] + Wines[2]), Wines[1] + Wines[2]);
    }

    for (int i = 3; i < N; i++)
    {
        DP[i] = max(max(DP[i - 1], DP[i - 2] + Wines[i]), DP[i - 3] + Wines[i - 1] + Wines[i]);
    }

    cout << DP[N - 1] << "\n";

    return 0;
}
