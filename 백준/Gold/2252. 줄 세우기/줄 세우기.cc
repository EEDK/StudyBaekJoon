#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> Graph;
    Graph.resize(N + 1);

    vector<int> InDegree;
    InDegree.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;

        Graph[A].push_back(B);
        InDegree[B]++;
    }

    queue<int> Queue;

    for (int i = 1; i <= N; i++)
    {
        if (InDegree[i] == 0)
        {
            Queue.push(i);
        }
    }

    vector<int> answer;
    while (!Queue.empty())
    {
        int now = Queue.front();

        Queue.pop();
        answer.push_back(now);

        for (const auto& adj : Graph[now])
        {
            InDegree[adj]--;
            if (InDegree[adj] == 0)
            {
                Queue.push(adj);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << answer[i] << " ";
    }

    cout << "\n";

    return 0;
}
