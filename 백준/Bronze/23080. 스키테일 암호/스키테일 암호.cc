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

int K;
string S;

int main()
{
    FASTIO;
    cin >> K >> S;

    for (int i = 0; i < S.size(); i += K)
    {
        cout << S[i];
    }
    cout << endl;

    return 0;
}
