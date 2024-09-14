#include <bits/stdc++.h>

using namespace std;

void Hanoi(int n, int from, int tmp, int to)
{
    if (n == 1)
    {
        cout << from << " " << to << "\n";
    }

    else
    {
        Hanoi(n - 1, from, to, tmp);
        cout << from << " " << to << "\n";
        Hanoi(n - 1, tmp, from, to);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    cout << (1 << N) - 1 << "\n";

    Hanoi(N, 1, 2, 3);

    return 0;
}
