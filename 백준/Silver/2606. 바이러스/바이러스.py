from collections import deque
import sys


def bfs(graph, startNode):
    visited = [False] * len(graph)
    queue = deque([startNode])
    visited[startNode] = True
    cnt = 0

    while queue:
        node = queue.popleft()
        cnt += 1

        for adjacent in graph[node]:
            if not visited[adjacent]:
                queue.append(adjacent)
                visited[adjacent] = True

    return cnt


N = int(sys.stdin.readline())
M = int(sys.stdin.readline())

graph = [[] for _ in range(N)]
for i in range(M):
    node1, node2 = map(int, sys.stdin.readline().split())
    graph[node1-1].append(node2-1)
    graph[node2-1].append(node1-1)

print(bfs(graph, 0)-1) 
