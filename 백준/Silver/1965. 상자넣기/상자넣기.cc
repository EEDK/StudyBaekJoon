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


int main()
{
    FASTIO

    int N;
    cin >> N;

    vi DP(1001, 1);
    vi Inputs(1001, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> Inputs[i];
    }

    for (int i = 1; i <= N; i++)
    {
        DP[i] = 1;
        for (int j = 1; j <= i; j++)
        {
            if (Inputs[j] < Inputs[i] && DP[i] < DP[j] + 1)
            {
                DP[i] = DP[j] + 1;
            }
        }
    }

    cout << *max_element(DP.begin(), DP.end()) << endl;

    return 0;
}
