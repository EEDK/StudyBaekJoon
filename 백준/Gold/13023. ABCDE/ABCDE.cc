#include <bits/stdc++.h>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
static bool isArrive;

void DFS(int now, int depth){
    if(depth == 5 || isArrive){
        isArrive = true;
        return;
    }
    
    visited[now] = true;
    
    for(int i : A[now]){
        if (!visited[i]){
            DFS(i, depth + 1);
        }
    }
    
    visited[now] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    isArrive = false;

    int N, M;
    cin >> N >> M;
    A.resize(N);
    visited = vector<bool>(N, false);

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;

        A[s].push_back(e);
        A[e].push_back(s);
    }

    for (int i = 0; i < N; ++i){
        DFS(i, 1);
        if(isArrive) break;
    }

    if (isArrive) cout << 1 << "\n";
    else cout << 0 << "\n";

    return 0;
}
