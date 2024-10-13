#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int N, M;

int main()
{
    FASTIO;

    cin >> N >> M;

    vector<int> Package(M, 0);
    vector<int> Each(M, 0);

    for (int i = 0; i < M; i++)
    {
        cin >> Package[i];
        cin >> Each[i];
    }

    sort(Package.begin(), Package.end());
    sort(Each.begin(), Each.end());

    int costWithPackageOnly = ((N / 6) + 1) * Package[0];

    int costWithEachOnly = N * Each[0];

    int costMixed = (N / 6) * Package[0] + (N % 6) * Each[0];

    cout << min({costWithPackageOnly, costWithEachOnly, costMixed}) << endl;


    return 0;
}
