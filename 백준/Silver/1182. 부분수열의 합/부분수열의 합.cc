#include <bits/stdc++.h>

using namespace std;


int N, S;
int answer = 0;

void Backtrack(int idx, int sum, vector<int> &Lst)
{
    if (idx == N)
    {
        if (sum == S) answer++;
        return;
    }

    Backtrack(idx + 1, sum, Lst);

    Backtrack(idx + 1, sum + Lst[idx], Lst);
}


int main()
{
    cin >> N >> S;

    vector<int> Inputs(N);

    for (int i = 0; i < N; i++)
    {
        cin >> Inputs[i];
    }

    Backtrack(0, 0, Inputs);

    if (S == 0) answer--;

    cout << answer << endl;

    return 0;
}
