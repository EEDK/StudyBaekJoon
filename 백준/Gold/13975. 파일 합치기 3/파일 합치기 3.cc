#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll T;

void solve(const vector<ll>& Input)
{
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (const auto& item : Input)
    {
        pq.push(item);
    }

    ll sum = 0;
    while (pq.size() > 1)
    {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();

        ll c = a + b;
        sum += c;
        pq.push(c);
    }

    cout << sum << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--)
    {
        ll K;
        cin >> K;
        vector<ll> Chapter(K);
        for (ll i = 0; i < K; i++)
        {
            cin >> Chapter[i];
        }

        solve(Chapter);
    }

    return 0;
}
