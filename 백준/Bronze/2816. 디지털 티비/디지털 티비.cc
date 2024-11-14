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

int N;
vector<string> Inputs;

int OnePos, TwoPos;

void Solve()
{
    if (OnePos > TwoPos)
    {
        TwoPos++;
    }
    for (int i = 0; i < OnePos; i++)
    {
        cout << '1';
    }
    for (int i = 0; i < OnePos; i++)
    {
        cout << '4';
    }


    if (TwoPos != 1)
    {
        for (int i = 0; i < TwoPos; i++) cout << '1';
        for (int i = 1; i < TwoPos; i++) cout << '4';
    }
}

int main()
{
    FASTIO

    cin >> N;

    Inputs.resize(N, "");
    FOR(i, N)
    {
        cin >> Inputs[i];
        if (Inputs[i] == "KBS1")
        {
            OnePos = i;
        }
        else if (Inputs[i] == "KBS2")
        {
            TwoPos = i;
        }
    }

    Solve();

    return 0;
}
