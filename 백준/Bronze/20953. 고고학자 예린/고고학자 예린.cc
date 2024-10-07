#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T;
    cin >> T;

    while (T--)
    {
        ll a, b;
        cin >> a >> b;

        cout << (a + b - 1) * (a + b) * (a + b) / 2 << "\n";
    }

    return 0;
}
