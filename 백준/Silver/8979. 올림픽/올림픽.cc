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

int N, K;

vvi Inputs;
int ranks[1001];

int main()
{
    FASTIO

    cin >> N >> K;
    Inputs.resize(N, vi(4, 0));

    for (int i = 0; i < N; ++i)
    {
        int num, gold, sliver, bronze;
        cin >> num >> gold >> sliver >> bronze;
        Inputs[i][0] = gold;
        Inputs[i][1] = sliver;
        Inputs[i][2] = bronze;
        Inputs[i][3] = num;
    }

    sort(Inputs.begin(), Inputs.end(), [](const vi &a, const vi &b) {
        if (a[0] != b[0])
            return a[0] > b[0];
        if (a[1] != b[1])
            return a[1] > b[1];
        return a[2] > b[2];
    });

    ranks[Inputs[0][3]] = 1;
    for (int i = 1; i < N; ++i)
    {
        if (Inputs[i][0] == Inputs[i - 1][0] && Inputs[i][1] == Inputs[i - 1][1] && Inputs[i][2] == Inputs[i - 1][2])
        {
            ranks[Inputs[i][3]] = ranks[Inputs[i - 1][3]];
        }
        else
        {
            ranks[Inputs[i][3]] = i + 1;
        }
    }

    cout << ranks[K] << endl;

    return 0;
}
