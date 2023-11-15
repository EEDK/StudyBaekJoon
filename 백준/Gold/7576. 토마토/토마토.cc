#include <bits/stdc++.h>

using namespace std;

struct Tomato {
  int x, y, days;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int tomatoRipeness(vector<vector<int>> &box, int M, int N) {
  queue<Tomato> q;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (box[i][j] == 1) {
        q.push({i, j, 0});
      }
    }
  }

  int days = 0;

  while (!q.empty()) {
    Tomato current = q.front();
    q.pop();
    days = current.days;

    for (int i = 0; i < 4; ++i) {
      int nx = current.x + dx[i];
      int ny = current.y + dy[i];

      if (nx >= 0 && nx < N && ny >= 0 && ny < M && box[nx][ny] == 0) {
        box[nx][ny] = 1;
        q.push({nx, ny, current.days + 1});
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (box[i][j] == 0) {
        return -1;
      }
    }
  }

  return days;
}

int main() {
  int M, N;
  cin >> M >> N;

  vector<vector<int>> box(N, vector<int>(M, 0));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> box[i][j];
    }
  }

  int result = tomatoRipeness(box, M, N);

  cout << result << endl;

  return 0;
}
