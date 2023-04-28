import sys
from collections import deque


def solution(n):
    answer = 0

    queue = deque()
    for i in range(1, n+1):
        queue.append(i)

    while len(queue) > 1:
        delCard = queue.popleft()
        appCard = queue.popleft()
        queue.append(appCard)

    return queue.popleft()


n = int(sys.stdin.readline())

print(solution(n))
