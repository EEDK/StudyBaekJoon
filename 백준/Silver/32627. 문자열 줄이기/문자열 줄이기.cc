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

int N, M;


int main()
{
    FASTIO

    string S;

    cin >> N >> M >> S;

    string tempStr = S;
    sort(tempStr.begin(), tempStr.end());

    unordered_map<char, int> toRemove;
    for (int i = 0; i < M; i++)
    {
        toRemove[tempStr[i]]++;
    }

    string result;
    for (char c : S)
    {
        if (toRemove[c] > 0)
        {
            toRemove[c]--;
        }
        else
        {
            result.push_back(c);
        }
    }

    cout << result << endl;


    return 0;
}
