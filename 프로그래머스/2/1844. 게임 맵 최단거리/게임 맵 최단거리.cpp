#include <vector>
#include <queue>
using namespace std;

const vector<int> dx{-1, 1, 0, 0};
const vector<int> dy{0, 0, -1, 1};

int solution(vector<vector<int>> maps) {
  int n = maps.size();
  int m = maps[0].size();
  vector<vector<int>> dist(n, vector<int>(m, -1));

  queue<pair<int, int>> q;
  q.push({0, 0});
  dist[0][0] = 1;

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
        continue;
      }
      if (maps[nx][ny] == 0) {
        continue;
      }
      if (dist[nx][ny] == -1) {
        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }

  int answer = dist[n - 1][m - 1];
  return answer == -1 ? -1 : answer;
}