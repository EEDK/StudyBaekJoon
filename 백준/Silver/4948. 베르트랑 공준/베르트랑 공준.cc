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

bool IsPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void Solve(int n)
{
    int start = n + 1;
    int end = 2 * n;

    int answer = 0;

    for (start; start <= end; start++)
    {
        if (IsPrime(start))
        {
            answer++;
        }
    }

    cout << answer << endl;
}

int main()
{
    FASTIO

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            break;
        }

        Solve(n);
    }

    return 0;
}
