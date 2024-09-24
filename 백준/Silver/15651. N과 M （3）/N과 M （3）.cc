#include <bits/stdc++.h>

using namespace std;

vector<int> Result;

int N, M;

void backtrack(int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; ++i)
        {
            cout << Result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        Result.push_back(i);
        backtrack(depth + 1);
        Result.pop_back();
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    backtrack(0);

    return 0;
}
