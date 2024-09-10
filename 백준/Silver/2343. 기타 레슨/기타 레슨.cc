#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<int> Lst;

    Lst.resize(N);

    int left = INT_MIN;
    int right = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> Lst[i];
        right += Lst[i];

        if (Lst[i] > left)
        {
            left = Lst[i];
        }
    }

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int sum = 0;
        int cnt = 0;

        for (int i = 0; i < N; i++)
        {
            if (sum + Lst[i] > mid)
            {
                cnt++;
                sum = 0;
            }
            sum += Lst[i];
        }

        if (sum != 0)
        {
            cnt++;
        }

        if (cnt > M)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << left << endl;

    return 0;
}
