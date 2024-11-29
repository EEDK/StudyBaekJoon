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

int N, K;
vi weights;

void Solve()
{
    sort(weights.begin(), weights.end());

    int left = 0;
    int right = N - 1;

    int cnt = 0;
    while (left < right)
    {
        int NowWeight = weights[left] + weights[right];

        if (NowWeight > K)
        {
            right--;
            continue;
        }
        else
        {
            left++;
            right--;
            cnt++;
        }
    }

    cout << cnt << endl;
}

int main()
{
    FASTIO

    cin >> N >> K;
    weights.resize(N);

    FOR(i, N)
    {
        cin >> weights[i];
    }

    Solve();

    return 0;
}
