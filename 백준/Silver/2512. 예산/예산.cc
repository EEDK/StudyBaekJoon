#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> Moneys;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    Moneys.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> Moneys[i];
    }

    cin >> M;

    sort(Moneys.begin(), Moneys.end());

    int left = 0;
    int right = Moneys[N - 1];
    int answer = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int sum = 0;

        for (int i = 0; i < N; i++)
        {
            if (Moneys[i] > mid)
            {
                sum += mid;
            }
            else
            {
                sum += Moneys[i];
            }
        }

        if (sum <= M)
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer << "\n";

    return 0;
}
