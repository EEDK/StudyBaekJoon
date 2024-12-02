#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF (~0U >> 2)
#define PB push_back
#define MOD 10007

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int N;
vi Inputs;

void Solve()
{
    vi Result(N, -1);
    stack<int> Stack;

    Stack.push(0);

    for (int i = 1; i < N; i++)
    {
        while (!Stack.empty() && Inputs[Stack.top()] < Inputs[i])
        {
            Result[Stack.top()] = Inputs[i];
            Stack.pop();
        }
        Stack.push(i);
    }

    while (!Stack.empty())
    {
        Result[Stack.top()] = -1;
        Stack.pop();
    }

    for (const auto& item : Result)
    {
        cout << item << " ";
    }
    cout << endl;
}

int main()
{
    FASTIO

    cin >> N;
    Inputs.resize(N, 0);

    FOR(i, N)
    {
        cin >> Inputs[i];
    }

    Solve();

    return 0;
}
