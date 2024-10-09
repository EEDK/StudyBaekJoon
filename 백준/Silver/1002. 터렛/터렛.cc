#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int x1, y1, r1;
        int x2, y2, r2;

        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        if (d == 0 && r1 == r2)
        {
            cout << -1 << '\n';
        }
        else if (d == r1 + r2)
        {
            cout << 1 << '\n';
        }
        else if (d == abs(r1 - r2))
        {
            cout << 1 << '\n';
        }
        else if (abs(r1 - r2) < d && d < r1 + r2)
        {
            cout << 2 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }

    return 0;
}
