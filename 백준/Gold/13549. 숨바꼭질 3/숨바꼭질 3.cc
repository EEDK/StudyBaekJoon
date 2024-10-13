#include <bits/stdc++.h>
#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int N, K;
bool visited[100001];

void BFS(int start)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty())
    {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (now == K)
        {
            cout << cnt << endl;
            return;
        }

        if (now * 2 <= 100000 && !visited[now * 2])
        {
            visited[now * 2] = true;
            q.push({now * 2, cnt});
        }

        if (now - 1 >= 0 && !visited[now - 1])
        {
            visited[now - 1] = true;
            q.push({now - 1, cnt + 1});
        }

        if (now + 1 <= 100000 && !visited[now + 1])
        {
            visited[now + 1] = true;
            q.push({now + 1, cnt + 1});
        }
    }
}

int main()
{
    FASTIO;

    cin >> N >> K;

    BFS(N);

    return 0;
}
