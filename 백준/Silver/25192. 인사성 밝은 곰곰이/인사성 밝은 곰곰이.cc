#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int N;

int main()
{
    FASTIO;

    cin >> N;

    int answer = 0;

    unordered_map<string, bool> Maps;

    FOR(i, N)
    {
        string inputs;
        cin >> inputs;

        if (inputs == "ENTER")
        {
            Maps.clear();
        }
        else
        {
            if (Maps.find(inputs) != Maps.end())
            {
                continue;
            }
            else
            {
                Maps[inputs] = true;
                answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}
