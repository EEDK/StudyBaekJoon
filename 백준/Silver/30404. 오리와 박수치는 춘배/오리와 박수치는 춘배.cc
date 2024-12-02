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

int N, K;
vi X;

void Solve()
{
    int answer = 0;
    int lastClapTime = -1;

    for (int i = 0; i < N; i++)
    {
        if (X[i] > lastClapTime)
        {
            answer++;
            lastClapTime = X[i] + K;
        }
    }

    cout << answer << endl;
}

int main()
{
    FASTIO

    cin >> N >> K;
    X.resize(N, 0);

    FOR(i, N)
    {
        cin >> X[i];
    }

    Solve();

    return 0;
}
