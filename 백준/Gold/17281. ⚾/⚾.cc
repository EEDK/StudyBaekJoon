#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N;
vector<ll> Taja = {1, 2, 3, 4, 5, 6, 7, 8};

ll GetScore(const vector<vector<ll>>& Inputs, const vector<ll>& Tarsoon)
{
    ll pos = 0;
    ll sum = 0;

    for (ll i = 0; i < Inputs.size(); i++)
    {
        ll outCount = 0;
        ll bases[3] = {0, 0, 0};

        while (outCount < 3)
        {
            ll result = Inputs[i][Tarsoon[pos % 9]];
            pos++;

            if (result == 0)
            {
                outCount++;
            }
            else
            {
                if (result == 4)
                {
                    sum += 1 + bases[0] + bases[1] + bases[2];
                    fill(bases, bases + 3, 0);
                }
                else
                {
                    if (result == 1)
                    {
                        sum += bases[2];
                        bases[2] = bases[1];
                        bases[1] = bases[0];
                        bases[0] = 1;
                    }
                    else if (result == 2)
                    {
                        sum += bases[2];
                        sum += bases[1];
                        bases[2] = bases[0];
                        bases[1] = 1;
                        bases[0] = 0;
                    }
                    else if (result == 3)
                    {
                        sum += bases[2];
                        sum += bases[1];
                        sum += bases[0];
                        bases[2] = 1;
                        bases[1] = 0;
                        bases[0] = 0;
                    }
                }
            }
        }
    }

    return sum;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<vector<ll>> Inputs(N, vector<ll>(9, 0));

    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < 9; j++)
        {
            cin >> Inputs[i][j];
        }
    }

    ll MaxScore = LONG_LONG_MIN;

    do
    {
        vector<ll> Lst;
        for (auto it = Taja.begin(); it != Taja.end(); ++it)
        {
            Lst.push_back(*it);
        }
        Lst.insert(Lst.begin() + 3, 0);
        ll NowScore = GetScore(Inputs, Lst);
        if (NowScore > MaxScore)
        {
            MaxScore = NowScore;
        }
    }
    while (next_permutation(Taja.begin(), Taja.end()));

    cout << MaxScore << "\n";

    return 0;
}
