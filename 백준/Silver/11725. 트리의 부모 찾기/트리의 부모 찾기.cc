#include <bits/stdc++.h>

using namespace std;

static int N;
static vector<int> Answer;
static vector<bool> Visited;
static vector<vector<int>> Tree;

void DFS(int number);

int main() {
    cin >> N;
    Visited.resize(N + 1);
    Tree.resize(N + 1);
    Answer.resize(N + 1);

    for (int i = 1; i < N; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        Tree[n1].push_back(n2);
        Tree[n2].push_back(n1);
    }

    DFS(1);

    for (int i = 2; i <= N; i++) {
        cout << Answer[i] << "\n";
    }

    return 0;
}

void DFS(int number) {
    Visited[number] = true;

    for (int i : Tree[number]) {
        if (!Visited[i]) {
            Answer[i] = number;
            DFS(i);
        }
    }
}