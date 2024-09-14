#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    vector<int> Inputs(N, 0);
    int sum = 0;
    int maxCost = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> Inputs[i];

        sum += Inputs[i];
        maxCost = max(maxCost, Inputs[i]);
    }

    cout << sum - maxCost << endl;

    return 0;
}
