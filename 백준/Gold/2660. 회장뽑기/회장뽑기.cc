#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF (~0U >> 2)
#define PB push_back
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int N;
vvi Graph;

int BFS(int Start)
{
    vector<int> Visited(N + 1, -1);
    queue<int> q;
    Visited[Start] = 0;
    q.push(Start);

    int MaxScore = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int neighbor : Graph[curr])
        {
            if (Visited[neighbor] == -1)
            {
                Visited[neighbor] = Visited[curr] + 1;
                MaxScore = max(MaxScore, Visited[neighbor]);
                q.push(neighbor);
            }
        }
    }

    return MaxScore;
}

void Solve()
{
    int MinScore = INF;
    vi Result;

    for (int i = 1; i < N + 1; i++)
    {
        int score = BFS(i);

        if (score < MinScore)
        {
            MinScore = score;
            Result.clear();
            Result.push_back(i);
        }
        else if (score == MinScore)
        {
            Result.push_back(i);
        }
    }

    cout << MinScore << " " << Result.size() << endl;
    for (int i : Result)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    FASTIO

    cin >> N;
    Graph.resize(N + 1);

    while (true)
    {
        int u, v;
        cin >> u >> v;

        if (u == -1 && v == -1)
        {
            break;
        }

        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    Solve();

    return 0;
}