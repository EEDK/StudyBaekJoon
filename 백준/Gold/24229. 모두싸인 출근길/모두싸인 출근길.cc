#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int>> input(N);

    for (int i = 0; i < N; i++)
    {
        cin >> input[i].first >> input[i].second;
    }

    sort(input.begin(), input.end());

    vector<pair<int, int>> merged;

    int left = input[0].first;
    int right = input[0].second;

    for (int i = 1; i < N; i++)
    {
        if (right >= input[i].first)
        {
            right = max(right, input[i].second);
        }
        else
        {
            merged.push_back({left, right});
            left = input[i].first;
            right = input[i].second;
        }
    }
    merged.push_back({left, right});

    int max_right = 0;
    int answer = 0;

    for (auto& range : merged)
    {
        int start = range.first;
        int end = range.second;
        if (max_right >= start)
        {
            max_right = max(max_right, end + (end - start));
            answer = end;
        }
    }

    cout << answer << "\n";

    return 0;
}
