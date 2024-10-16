#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;

ll N, M;
vector<ll> A;

int main()
{
    FASTIO
    cin >> N >> M;

    A.resize(N);

    FOR(i, N)
    {
        cin >> A[i];
    }

    vector<ll> Sum(N + 1);

    for (int i = 1; i <= N; i++)
    {
        Sum[i] = A[i - 1] + Sum[i - 1];
    }

    int left = 0;
    int right = 1;

    int answer = 0;
    while (right <= N)
    {
        ll current_sum = Sum[right] - Sum[left];

        if (current_sum < M)
        {
            right++;
        }
        else if (current_sum == M)
        {
            answer++;
            right++;
        }
        else
        {
            left++;
        }

        if (left == right)
        {
            right++;
        }
    }

    cout << answer << endl;

    return 0;
}
