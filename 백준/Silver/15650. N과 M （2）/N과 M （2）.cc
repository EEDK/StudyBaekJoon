#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> Numbers(N, 0);
    fill(Numbers.begin(), Numbers.begin() + M, 1);


    do
    {
        for (int i = 0; i < N; i++)
        {
            if (Numbers[i] == 1)
            {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
    }
    while (prev_permutation(Numbers.begin(), Numbers.end()));

    return 0;
}
