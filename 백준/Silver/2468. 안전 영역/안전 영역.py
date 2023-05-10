from collections import deque


def bfs(maps, visited, startNode, n, target):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    queue = deque()
    queue.append(startNode)

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and maps[nx][ny] > target:
                queue.append((nx, ny))
                visited[nx][ny] = True


def solution(arr, n):
    tmp = [1]
    idx = 1
    while True:
        visited = [[False] * n for _ in range(n)]

        isOver = False
        cnt = 0
        for i in range(n):
            for j in range(n):
                if arr[i][j] > idx and not visited[i][j]:
                    bfs(arr, visited, (i, j), n, idx)
                    cnt += 1
                    isOver = True

        if not isOver:
            break
        tmp.append(cnt)
        idx += 1

    print(max(tmp))


n = int(input(''))
city = [list(map(int, input().split())) for _ in range(n)]


solution(city, n)
