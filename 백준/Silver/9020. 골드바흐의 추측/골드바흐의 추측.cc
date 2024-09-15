#include <bits/stdc++.h>

using namespace std;

bool isPrime(int N)
{
    if (N <= 1) return false;
    if (N == 2 || N == 3) return true;
    if (N % 2 == 0 || N % 3 == 0) return false;

    for (int i = 5; i * i <= N; i += 6)
    {
        if (N % i == 0 || N % (i + 2) == 0) return false;
    }

    return true;
}

void GoldBar(int Input)
{
    int a = Input / 2;
    int b = Input / 2;

    while (!isPrime(a) || !isPrime(b))
    {
        a--;
        b++;
    }

    cout << a << " " << b << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        GoldBar(temp);
    }

    return 0;
}
