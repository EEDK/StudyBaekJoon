#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<ll> Length(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> Length[i];
    }

    vector<ll> Cost(N);
    for (int i = 0; i < N; i++)
    {
        cin >> Cost[i];
    }

    ll result = 0;
    ll MinCost = Cost[0];

    for (int i = 0; i < N - 1; i++)
    {
        if (Cost[i] < MinCost)
        {
            MinCost = Cost[i];
        }
        result += MinCost * Length[i];
    }

    cout << result << "\n";

    return 0;
}
