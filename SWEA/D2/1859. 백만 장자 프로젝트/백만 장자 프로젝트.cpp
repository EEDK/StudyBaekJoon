#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF (~0U >> 2)
#define PB push_back
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

ll Solve(int n, vector<ll> Inputs)
{
    ll Result = 0;
    ll maxPrice = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        if (Inputs[i] > maxPrice)
        {
            maxPrice = Inputs[i];
        }
        else
        {
            Result += maxPrice - Inputs[i];
        }
    }

    return Result;
}


int main()
{
    FASTIO

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;

        vector<ll> Inputs(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> Inputs[i];
        }

        cout << "#" << test_case << " " << Solve(n, Inputs) << endl;
    }


    return 0;
}
