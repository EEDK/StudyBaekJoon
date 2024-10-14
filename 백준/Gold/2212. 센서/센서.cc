#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int N, K;
vector<int> Inputs;

int Solve()
{
    if (N <= K)
        return 0;
    
    sort(Inputs.begin(), Inputs.end());
    vector<int> Gaps;
    for (int i = 1; i < N; i++)
    {
        Gaps.push_back(Inputs[i] - Inputs[i - 1]);
    }

    sort(Gaps.begin(), Gaps.end(), greater<int>());


    return accumulate(Gaps.begin() + K - 1, Gaps.end(), 0);
}

int main()
{
    FASTIO;

    cin >> N >> K;
    Inputs.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> Inputs[i];
    }

    cout << Solve() << endl;

    return 0;
}
