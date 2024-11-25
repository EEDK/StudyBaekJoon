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
    vector<int> distance(N, INF);
    queue<int> q;
    distance[Start] = 0;
    q.push(Start);

    int max_distance = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int neighbor : Graph[curr])
        {
            if (distance[neighbor] == INF)
            {
                distance[neighbor] = distance[curr] + 1;
                max_distance = max(max_distance, distance[neighbor]);
                q.push(neighbor);
            }
        }
    }

    return max_distance;
}

void Solve()
{
    int MinScore = INF;
    vi Result;

    for (int i = 0; i < N; i++)
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
        cout << i + 1 << " ";
    }
    cout << endl;
}

int main()
{
    FASTIO

    cin >> N;
    Graph.resize(N);

    while (true)
    {
        int u, v;
        cin >> u >> v;

        if (u == -1 && v == -1)
        {
            break;
        }

        Graph[u-1].push_back(v-1);
        Graph[v-1].push_back(u-1);
    }

    Solve();

    return 0;
}