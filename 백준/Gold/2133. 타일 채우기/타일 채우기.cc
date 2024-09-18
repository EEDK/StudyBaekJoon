#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char** argv)
{
    int N;

    cin >> N;

    vector<ll> DP(31, 0);
    DP[0] = 1;
    DP[2] = 3;

    for (int i = 4; i <= 30; i += 2)
    {
        DP[i] = DP[i - 2] * 4 - DP[i - 4];
    }

    cout << DP[N] << "\n";

    return 0;
}
