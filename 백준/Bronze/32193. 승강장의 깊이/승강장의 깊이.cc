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

int main()
{
    FASTIO

    int N;
    cin >> N;

    int surface_height = 0, platform_height = 0;

    for (int i = 1; i <= N; ++i)
    {
        int A, B;
        cin >> A >> B;

        surface_height += A;
        platform_height += B;

        int depth = surface_height - platform_height;

        cout << depth << endl;
    }

    return 0;
}
