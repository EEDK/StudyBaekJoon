#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> Graph;
vector<int> Distance;

void BFS(int startPos, int K) {
	queue<int> Queue;
	Queue.push(startPos);
	Distance[startPos] = 0;

	while (!Queue.empty()) {
		int current = Queue.front();
		Queue.pop();

		for (int next : Graph[current]) {
			if (Distance[next] == -1) {
				Distance[next] = Distance[current] + 1;
				Queue.push(next);
			}
		}
	}

	bool found = false;
	for (int i = 1; i < Distance.size(); i++) {
		if (Distance[i] == K) {
			cout << i << endl;
			found = true;
		}
	}

	if (!found) {
		cout << -1 << endl;
	}
}

int main() {
	int N, M, K, X;

	cin >> N >> M >> K >> X;

	Graph.resize(N + 1);
	Distance.resize(N + 1, -1);  

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Graph[a].push_back(b);
	}

	BFS(X, K);

	return 0;
}