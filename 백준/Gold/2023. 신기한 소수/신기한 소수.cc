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
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int N;

int digit[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

string tempNum;

void BackTrack(int size)
{
    if (size >= N)
    {
        cout << tempNum << endl;
        return;
    }

    for (int i = 1; i < 10; i++)
    {
        tempNum += digit[i] + '0';
        if (IsPrime(stoi(tempNum)))
        {
            BackTrack(size + 1);
        }
        tempNum.pop_back();
    }
}

void solve(int num)
{
    tempNum.clear();
    tempNum += num + '0';
    BackTrack(1);
}
int main()
{
    FASTIO
    cin >> N;

    solve(2);
    solve(3);
    solve(5);
    solve(7);

    return 0;
}
