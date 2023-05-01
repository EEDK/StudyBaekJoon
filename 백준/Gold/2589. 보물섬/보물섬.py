from collections import deque


def bfs(x, y):
    visited = [[False] * m for _ in range(n)]
    queue = deque([(x, y, 0)])  # 시작점 좌표와 거리를 큐에 저장
    visited[x][y] = True
    max_dist = 0  # 최장 거리 초기화

    while queue:
        x, y, dist = queue.popleft()
        max_dist = max(max_dist, dist)  # 현재까지의 거리 중 최장 거리 갱신

        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:  # 4방향 탐색
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and board[nx][ny] == 'L':
                visited[nx][ny] = True
                queue.append((nx, ny, dist+1))

    return max_dist


n, m = map(int, input().split())
board = [input() for _ in range(n)]

ans = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == 'L':
            ans = max(ans, bfs(i, j))

print(ans)
