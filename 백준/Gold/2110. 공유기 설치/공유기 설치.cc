#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back

int N, C;
vector<int> houses;

bool canPlaceRouters(int dist) {
    int count = 1;
    int last_router = houses[0];

    for (int i = 1; i < N; i++) {
        if (houses[i] - last_router >= dist) {
            count++;
            last_router = houses[i];
        }
    }
    return count >= C;
}

int main() {
    FASTIO
    cin >> N >> C;
    houses.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());

    int low = 1;
    int high = houses[N - 1] - houses[0];
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlaceRouters(mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}