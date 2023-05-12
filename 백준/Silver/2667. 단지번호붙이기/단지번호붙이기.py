from collections import deque


def bfs(maps, visited, startNode):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    queue = deque()
    queue.append(startNode)
    result = 1

    while queue:
        x, y = queue.popleft()
        visited[x][y] = True
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if maps[nx][ny] == 1 and not visited[nx][ny]:
                visited[nx][ny] = True
                queue.append((nx, ny))
                result += 1
    return result


n = int(input())
graph = []
for i in range(n):
    graph.append(list(map(int, input())))

visited = [[False] * n for _ in range(n)]
answer = []
for i in range(n):
    for j in range(n):
        if (graph[i][j] == 1) and (not visited[i][j]):
            answer.append(bfs(graph, visited, (i, j)))

answer.sort()
print(len(answer))
for i in range(len(answer)):
    print(answer[i])
