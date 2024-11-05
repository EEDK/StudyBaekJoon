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

int N, T;
vi a;

vi TDivisor;

void GetTDivisor()
{
    TDivisor.push_back(1);
    if (T > 1)
    {
        TDivisor.push_back(T);
    }

    for (int i = 2; i <= sqrt(T); i++)
    {
        if (T % i == 0)
        {
            TDivisor.push_back(i);
            if (i != T / i)
            {
                TDivisor.push_back(T / i);
            }
        }
    }
    sort(TDivisor.begin(), TDivisor.end());
}

void Solution()
{
    GetTDivisor();

    int totalGap = 0;

    for (int i = 0; i < N; i++)
    {
        int NowA = a[i];
        int MinGap = INF;

        for (int j = 0; j < TDivisor.size(); j++)
        {
            int divisor = TDivisor[j];
            int gap = abs(NowA - divisor);

            if (gap < MinGap)
            {
                MinGap = gap;
            }
        }

        totalGap += MinGap;
    }

    cout << totalGap << endl;
}

int main()
{
    FASTIO

    cin >> N >> T;
    a.resize(N);

    FOR(i, N)
    {
        cin >> a[i];
    }

    Solution();

    return 0;
}
