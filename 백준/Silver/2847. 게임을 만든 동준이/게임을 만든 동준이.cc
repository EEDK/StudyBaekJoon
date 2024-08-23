#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int Input[N];

    for (int i = 0; i < N; ++i)
    {
        cin >> Input[i];
    }

    int sum = 0;
    for (int i = N - 2; i >= 0; i--)
    {
        int NextLevel = Input[i + 1];
        int NowLevel = Input[i];

        if (NextLevel <= NowLevel)
        {
            int Diff = NowLevel - NextLevel;
            Input[i] -= (Diff + 1);

            sum += (Diff + 1);
        }
    }

    cout << sum << "\n";

    return 0;
}
