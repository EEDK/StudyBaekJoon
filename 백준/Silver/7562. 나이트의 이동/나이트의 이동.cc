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

int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};

void Solve(int size, pii NowPos, pii TargetPos)
{
    vvi Visited(size, vi(size, 0));

    queue<pii> q;
    q.push(NowPos);
    Visited[NowPos.first][NowPos.second] = 1;

    int cnt = 0;
    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            pii now = q.front();
            q.pop();

            if (now == TargetPos)
            {
                cout << cnt << endl;
                return;
            }

            FOR(i, 8)
            {
                int ny = now.first + dy[i];
                int nx = now.second + dx[i];

                if (ny >= 0 && nx >= 0 && ny < size && nx < size && !Visited[ny][nx])
                {
                    Visited[ny][nx] = 1;
                    q.push({ny, nx});
                }
            }
        }

        cnt++;
    }

    cout << -1 << endl;
}

int main()
{
    FASTIO

    int T;
    cin >> T;
    while (T--)
    {
        int l;
        pii NowPos;
        pii TargetPos;

        cin >> l;
        cin >> NowPos.first >> NowPos.second;
        cin >> TargetPos.first >> TargetPos.second;

        Solve(l, NowPos, TargetPos);
    }

    return 0;
}
