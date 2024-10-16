#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define MAX 51

using namespace std;

struct FireBall
{
    int m, s, d;
};

int N, M, K;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<FireBall> fireBall[MAX][MAX];

void moveBall()
{
    vector<FireBall> tmpBall[MAX][MAX];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            while (!fireBall[i][j].empty())
            {
                FireBall fb = fireBall[i][j].back();
                fireBall[i][j].pop_back();

                int s = fb.s % N;
                int d = fb.d;

                int nx = i + dx[d] * s;
                int ny = j + dy[d] * s;

                if (nx < 1) nx += N;
                if (nx > N) nx -= N;
                if (ny < 1) ny += N;
                if (ny > N) ny -= N;

                tmpBall[nx][ny].push_back(fb);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            fireBall[i][j] = tmpBall[i][j];
        }
    }
}

void divideBall()
{
    vector<FireBall> tmpBall[MAX][MAX];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (fireBall[i][j].size() == 1)
            {
                tmpBall[i][j] = fireBall[i][j];
            }
            else if (fireBall[i][j].size() >= 2)
            {
                int totalS = 0;
                int totalM = 0;
                bool even = false, odd = false;
                int ballCount = fireBall[i][j].size();

                for (FireBall& fb : fireBall[i][j])
                {
                    totalS += fb.s;
                    totalM += fb.m;
                    if (fb.d % 2 == 0) even = true;
                    else odd = true;
                }

                int newM = totalM / 5;
                int newS = totalS / ballCount;

                if (newM > 0)
                {
                    int startDir = (even && odd) ? 1 : 0;
                    for (int d = startDir; d < 8; d += 2)
                    {
                        tmpBall[i][j].push_back({newM, newS, d});
                    }
                }
            }
            fireBall[i][j].clear();
            fireBall[i][j] = tmpBall[i][j];
        }
    }
}

int main()
{
    FASTIO

    cin >> N >> M >> K;

    FOR(i, M)
    {
        int x, y, m, s, d;
        cin >> x >> y >> m >> s >> d;
        fireBall[x][y].push_back({m, s, d});
    }

    FOR(i, K)
    {
        moveBall();
        divideBall();
    }

    long long totalM = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (FireBall& fb : fireBall[i][j])
            {
                totalM += fb.m;
            }
        }
    }

    cout << totalM << endl;

    return 0;
}
