from collections import deque

def bfs(maps, visited, startNode, targetNode):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    n = len(maps)
    m = len(maps[0])
    
    queue = deque()
    queue.append(startNode)
    visited[startNode[0]][startNode[1]] = True
    
    while queue:
        x, y = queue.popleft()
        
        if (x, y) == targetNode:
            return visited[x][y] - 1
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if nx >= n or nx < 0 or ny >= m or ny < 0:
                continue
            if maps[nx][ny] == 'X' or visited[nx][ny]:
                continue
            
            queue.append((nx, ny))
            visited[nx][ny] = visited[x][y] + 1

    return -1

def solution(maps):
    n = len(maps)
    m = len(maps[0])
    
    startNode = None
    leverNode = None
    endNode = None
    
    for i in range(n):
        for j in range(m):
            if maps[i][j] == 'S':
                startNode = (i, j)
            elif maps[i][j] == 'L':
                leverNode = (i, j)
            elif maps[i][j] == 'E':
                endNode = (i, j)
                
    visited = [[0] * m for _ in range(n)]
    
    phase1 = bfs(maps, visited, startNode, leverNode)
    
    if phase1 != -1:
        visited = [[0] * m for _ in range(n)]
        phase2 = bfs(maps, visited, leverNode, endNode)
        if phase2 != -1:
            return phase1 + phase2

    return -1
