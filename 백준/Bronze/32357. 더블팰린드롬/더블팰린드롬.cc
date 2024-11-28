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

int N;
vector<string> Inputs;

bool IsPalindrome(const string& s)
{
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}


int main()
{
    FASTIO

    cin >> N;
    Inputs.resize(N);

    int answer = 0;
    FOR(i, N)
    {
        string s;
        cin >> s;
        if (IsPalindrome(s))
        {
            answer++;
        }
    }

    cout << answer * (answer - 1) << endl;

    return 0;
}
