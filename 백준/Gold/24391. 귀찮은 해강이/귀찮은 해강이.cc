#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
vector<ll> Parent, Rank;

ll find(ll Lst)
{
    if (Parent[Lst] != Lst)
    {
        Parent[Lst] = find(Parent[Lst]);
    }
    return Parent[Lst];
}

void unionSet(ll x, ll y)
{
    ll root1 = find(x);
    ll root2 = find(y);

    if (root1 != root2)
    {
        if (Rank[root1] > Rank[root2])
        {
            Parent[root2] = root1;
        }
        else if (Rank[root1] < Rank[root2])
        {
            Parent[root1] = root2;
        }
        else
        {
            Parent[root2] = root1;
            Rank[root1]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, M;
    cin >> N >> M;

    Parent.resize(N + 1);
    Rank.resize(N + 1, 0);

    for (ll i = 1; i <= N; i++)
    {
        Parent[i] = i;
    }

    for (ll i = 0; i < M; i++)
    {
        ll u, v;
        cin >> u >> v;
        unionSet(u, v);
    }

    vector<ll> Timetable(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> Timetable[i];
    }

    ll answer = 0;
    ll firstRoot = find(Timetable[0]);

    for (ll i = 1; i < N; i++)
    {
        if (firstRoot != find(Timetable[i]))
        {
            firstRoot = find(Timetable[i]);
            answer++;
        }
    }

    cout << answer << "\n";

    return 0;
}
