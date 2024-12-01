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
int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};

vvi Result;
vi tempLst;

vi GuGudan;

int main()
{
    FASTIO

    int N;
    cin >> N;

    GuGudan.PB(1);
    for (int i = 2; i < 10; i++)
    {
        FOR(j, 10)
        {
            GuGudan.PB(i * j);
        }
    }

    if (find(GuGudan.begin(), GuGudan.end(), N) == GuGudan.end())
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
    }

    return 0;
}
