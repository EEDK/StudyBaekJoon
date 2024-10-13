#include <bits/stdc++.h>

using namespace std;

int N, A, B;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> A >> B;

    int start_good = 1;
    int start_bad = 1;

    for (int i = 0; i < N; i++)
    {
        start_good += A;
        start_bad += B;

        if (start_bad > start_good)
        {
            swap(start_good, start_bad);
        }
        if (start_bad == start_good)
        {
            start_bad--;
        }
    }

    cout << start_good << " " << start_bad << "\n";

    return 0;
}
