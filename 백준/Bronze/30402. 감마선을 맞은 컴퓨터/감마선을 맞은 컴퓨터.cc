#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF (~0U >> 2)
#define PB push_back
#define MOD 10007

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

char Map[16][16];

int main()
{
    FASTIO

    memset(Map, '0', sizeof(Map));

    FOR(i, 15)
    {
        FOR(j, 15)
        {
            cin >> Map[i][j];

            if (Map[i][j] == 'w')
            {
                cout << "chunbae" << endl;
                return 0;
            }

            if (Map[i][j] == 'b')
            {
                cout << "nabi" << endl;
                return 0;
            }

            if (Map[i][j] == 'g')
            {
                cout << "yeongcheol" << endl;
                return 0;
            }
        }
    }

    return 0;
}
