#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF (~0U >> 2)
#define PB push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int R, C;
char Inputs[21][21] = {0};
bool visited[26];

bool IsRanged(int y, int x)
{
    return (y >= 0 && y < R && x >= 0 && x < C);
}

int maxCnt = 0;

void dfs(int y, int x, int cnt)
{
    maxCnt = max(maxCnt, cnt);

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (IsRanged(ny, nx))
        {
            int alphabetIdx = Inputs[ny][nx] - 'A';
            if (!visited[alphabetIdx])
            {
                visited[alphabetIdx] = true;
                dfs(ny, nx, cnt + 1);
                visited[alphabetIdx] = false;
            }
        }
    }
}

int main()
{
    FASTIO
    cin >> R >> C;

    FOR(i, R)
    {
        FOR(j, C)
        {
            cin >> Inputs[i][j];
        }
    }

    visited[Inputs[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << maxCnt << endl;
    return 0;
}
