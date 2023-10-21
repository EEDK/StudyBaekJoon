#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;

const vector<int> dx = {-1, 1, 0, 0};
const vector<int> dy = {0, 0, -1, 1};

int bfs(vector<vector<int>> &maps, int startX, int startY) {
  int n = maps.size();
  int m = maps[0].size();
  int size = 1;

  queue<pair<int, int>> q;
  q.push(make_pair(startX, startY));
  maps[startX][startY] = 0;

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1) {
        size++;
        maps[nx][ny] = 0;
        q.push(make_pair(nx, ny));
      }
    }
  }

  return size;
}

vector<int> solution(vector<vector<int>> maps) {
  int n = maps.size();
  int m = maps[0].size();

  vector<int> arts;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (maps[i][j] == 1) {
        arts.push_back(bfs(maps, i, j));
      }
    }
  }

  return arts;
}

int main() {

  int n, m;
  cin >> n >> m;

  vector<vector<int>> maps;
  for (int i = 0; i < n; i++) {
    vector<int> tmp;
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      tmp.push_back(a);
    }
    maps.push_back(tmp);
  }
  vector<int> result = solution(maps);
  if (result.empty()) {
    cout << 0 << " " << 0 << endl;
  } else {
    cout << result.size() << " " << *max_element(result.begin(), result.end()) << endl;
  }
}
