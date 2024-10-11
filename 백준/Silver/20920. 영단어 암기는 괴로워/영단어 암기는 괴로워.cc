#include <bits/stdc++.h>

using namespace std;


int N, M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    unordered_map<string, int> Map;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        if (str.size() >= M)
        {
            Map[str] += 1;
        }
    }

    vector<pair<string, int>> result;
    for (const auto& Lst : Map)
    {
        result.push_back(Lst);
    }

    sort(result.begin(), result.end(), [](const pair<string, int>& a, const pair<string, int>& b)
    {
        if (a.second == b.second)
        {
            if (a.first.size() == b.first.size())
            {
                return a.first < b.first;
            }
            return a.first.size() > b.first.size();
        }
        return a.second > b.second;
    });

    for (const auto& Lst : result)
    {
        cout << Lst.first << "\n";
    }

    return 0;
}
