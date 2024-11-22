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
set<pair<int, int>> visited;

int answer = 0;

void dfs(int n, string num, int cnt)
{
    if (n == cnt)
    {
        answer = max(answer, stoi(num));
        return;
    }

    for (int i = 0; i < num.size() - 1; i++)
    {
        for (int j = i + 1; j < num.size(); j++)
        {
            swap(num[i], num[j]);
            int currentNum = stoi(num);
            if (visited.find({n, currentNum}) == visited.end())
            {
                visited.insert({n, currentNum});
                dfs(n + 1, num, cnt);
            }
            swap(num[i], num[j]);
        }
    }
}

string Solve(string N, int cnt)
{
    visited.clear();
    answer = 0;
    dfs(0, N, cnt);
    return to_string(answer);
}


int main(int argc, char** argv)
{
    FASTIO
    int test_case;
    int T;

    // freopen("input.txt", "r", stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string N;
        int cnt;
        cin >> N >> cnt;

        cout << "#" << test_case << " " << Solve(N, cnt) << endl;
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}
