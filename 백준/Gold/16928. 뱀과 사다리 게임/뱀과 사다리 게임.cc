#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define INF 987654321
#define PB push_back
typedef pair<int, int> pii;

int N, M;
int Graph[101];
bool Visited[101];

int BFS(int Pos) {
    queue<int> Queue;
    Queue.push(Pos);
    Visited[Pos] = true;

    int count = 0;
    while (!Queue.empty()) {
        int QueueSize = Queue.size();
        count++;

        for (int i = 0; i < QueueSize; i++) {
            int NowPos = Queue.front();
            Queue.pop();

            for (int dice = 1; dice <= 6; dice++) {
                int GoPos = NowPos + dice;

                if (GoPos > 100)
                    continue;
                GoPos = Graph[GoPos];

                if (GoPos == 100) {
                    return count;
                }

                if (!Visited[GoPos]) {
                    Visited[GoPos] = true;
                    Queue.push(GoPos);
                }
            }
        }
    }

    return -1;
}

int main() {
    FASTIO

    cin >> N >> M;

    for (int i = 1; i <= 100; i++) {
        Graph[i] = i;
    }

    FOR(i, N) {
        int x, y;
        cin >> x >> y;
        Graph[x] = y;
    }

    FOR(i, M) {
        int u, v;
        cin >> u >> v;
        Graph[u] = v;
    }

    cout << BFS(1) << endl;

    return 0;
}