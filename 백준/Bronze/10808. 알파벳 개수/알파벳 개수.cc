#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;

    vector<int> Result(26, 0);

    for (const auto& op : s)
    {
        Result[op - '0' - 49] += 1;
    }

    for (const int& item : Result)
    {
        cout << item << " ";
    }

    cout << "\n";

    return 0;
}
