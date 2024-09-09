#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<pair<int, string>> pq;

    for (int i = 0; i < N; i++)
    {
        int age;
        string str;

        cin >> age >> str;

        pq.push_back({age, str});
    }

    stable_sort(pq.begin(), pq.end(), [](const pair<int, string> a, const pair<int, string> b)
    {
        return a.first < b.first;
    });

    for (int i = 0; i < N; i++)
    {
        cout << pq[i].first << " " << pq[i].second << "\n";
    }


    return 0;
}
