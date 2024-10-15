#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int N, K;
vector<int> kit;
int validCount = 0;

void findPlans(int day, int currentWeight, vector<bool>& used)
{
    if (day == N)
    {
        validCount++;
        return;
    }

    FOR(i, N)
    {
        if (!used[i])
        {
            used[i] = true;

            int newWeight = currentWeight + kit[i] - K;

            if (newWeight >= 500)
            {
                findPlans(day + 1, newWeight, used);
            }

            used[i] = false;
        }
    }
}

int main()
{
    cin >> N >> K;
    kit.resize(N);
    FOR(i, N)
    {
        cin >> kit[i];
    }

    vector<bool> used(N, false);

    findPlans(0, 500, used);

    cout << validCount << endl;

    return 0;
}
