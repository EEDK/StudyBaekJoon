from collections import deque

n, m = map(int, input().split())
paper = [list(map(int, input().split())) for _ in range(n)]

# 방문한 위치를 저장하는 visited 리스트
visited = [[False]*m for _ in range(n)]

# 방향 벡터 정의
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(x, y):
    q = deque()
    q.append((x, y))
    visited[x][y] = True
    count = 1  # 그림의 크기를 세는 변수

    while q:
        x, y = q.popleft()

        # 현재 위치에서 상하좌우 탐색
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 도화지 범위를 벗어난 경우
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue

            # 이미 방문한 위치이거나 그림이 아닌 경우
            if visited[nx][ny] or paper[nx][ny] == 0:
                continue

            q.append((nx, ny))
            visited[nx][ny] = True
            count += 1

    return count


count = 0
max_size = 0  # 가장 큰 그림의 크기를 저장하는 변수

for i in range(n):
    for j in range(m):
        if not visited[i][j] and paper[i][j] == 1:
            count += 1
            size = bfs(i, j)
            if size > max_size:
                max_size = size

print(count)
print(max_size)
