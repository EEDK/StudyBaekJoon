#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int minX = abs(x - 0);
    int maxX = abs(w - x);

    int minY = abs(y - 0);
    int maxY = abs(h - y);

    cout << min(min(minX, maxX), min(minY, maxY)) << "\n";

    return 0;
}
