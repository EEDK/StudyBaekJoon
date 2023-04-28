from itertools import combinations
from collections import deque
import copy

N, M = map(int, input().split())
graph = []
for _ in range(N):
    graph.append(list(map(int, input().split())))

# 빈 칸 리스트와 바이러스 위치 리스트를 만듦
blanks = []
virus = []
for i in range(N):
    for j in range(M):
        if graph[i][j] == 0:
            blanks.append((i, j))
        elif graph[i][j] == 2:
            virus.append((i, j))

# 상하좌우 이동을 위한 dx, dy 리스트
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# BFS로 바이러스 전파


def bfs(graph):
    queue = deque(virus)
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < M and graph[nx][ny] == 0:
                graph[nx][ny] = 2
                queue.append((nx, ny))


# 빈 칸 중 3개를 선택하여 벽을 세우는 모든 경우를 찾음
comb = combinations(blanks, 3)

# 모든 경우의 수를 차례대로 검사하여 안전 영역 크기의 최댓값을 구함
result = 0
for walls in comb:
    # 벽을 세운 후의 지도를 복사하여 만듦
    new_graph = copy.deepcopy(graph)
    for x, y in walls:
        new_graph[x][y] = 1

    # BFS로 바이러스 전파
    bfs(new_graph)

    # 안전 영역 크기 계산
    cnt = 0
    for i in range(N):
        for j in range(M):
            if new_graph[i][j] == 0:
                cnt += 1
    result = max(result, cnt)

print(result)
