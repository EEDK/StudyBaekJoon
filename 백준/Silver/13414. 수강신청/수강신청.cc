#include <bits/stdc++.h>

using namespace std;

int main()
{
    int K, L;

    cin >> K >> L;

    unordered_map<string, int> map;

    for (int i = 0; i < L; i++)
    {
        string user;
        cin >> user;

        map[user] = i;
    }

    vector<pair<string, int>> finalOrder;


    for (const auto& item : map)
    {
        finalOrder.push_back(item);
    }

    sort(finalOrder.begin(), finalOrder.end(), [](pair<string, int> a, pair<string, int> b)
    {
        return a.second < b.second;
    });

    if (K > finalOrder.size())
    {
        K = finalOrder.size();
    }

    for (int i = 0; i < K; i++)
    {
        cout << finalOrder[i].first << "\n";
    }

    return 0;
}
