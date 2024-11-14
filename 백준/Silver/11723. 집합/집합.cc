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

    unordered_map<int, bool> Maps;

    int M;
    cin >> M;

    int S = 0;

    while (M--)
    {
        string op;
        int x;

        cin >> op;

        if (op == "add")
        {
            cin >> x;
            S |= (1 << (x - 1));
        }
        else if (op == "remove")
        {
            cin >> x;
            S &= ~(1 << (x - 1));
        }
        else if (op == "check")
        {
            cin >> x;
            cout << ((S & (1 << (x - 1))) ? 1 : 0) << endl;
        }
        else if (op == "toggle")
        {
            cin >> x;
            S ^= (1 << (x - 1));
        }
        else if (op == "all")
        {
            S = (1 << 20) - 1;
        }
        else if (op == "empty")
        {
            S = 0;
        }
    }

    return 0;
}
