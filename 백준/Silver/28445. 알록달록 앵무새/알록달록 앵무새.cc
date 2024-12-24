#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FASTIO                                                                                                         \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define INF (~0U >> 2)
#define PB push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

vector<string> Inputs;

void BackTrack(int pos)
{
    if (pos >= Inputs.size())
    {
        return;
    }

    for (int i = 0; i < Inputs.size(); i++)
    {
        cout << Inputs[pos] << " ";
        cout << Inputs[i] << endl;
    }

    BackTrack(pos + 1);
}

int main()
{
    FASTIO

    FOR(i, 4)
    {
        string input;
        cin >> input;
        Inputs.PB(input);
    }
    sort(Inputs.begin(), Inputs.end());
    Inputs.erase(unique(Inputs.begin(), Inputs.end()), Inputs.end());

    BackTrack(0);

    return 0;
}
