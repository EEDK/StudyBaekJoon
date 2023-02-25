from collections import deque


def solution(maps):
    return bfs(maps, 0, 0)


def bfs(graph, x, y):
    n = len(graph)
    m = len(graph[0])

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    queue = deque()
    queue.append((x, y))

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if graph[nx][ny] == 0:
                continue
            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                queue.append((nx, ny))

    if graph[-1][-1] == 1:
        return -1
    return graph[-1][-1]
