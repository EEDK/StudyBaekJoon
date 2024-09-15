#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int> pq;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        pq.push(n);
    }

    int sum = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int c = a + b;
        sum += a * b;
        pq.push(c);
    }

    cout << sum << "\n";

    return 0;
}
