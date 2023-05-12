from collections import deque


def solution(target, n):
    answer = 0
    queue = deque(range(1, n+1))

    for num in target:
        idx = queue.index(num)
        length = len(queue)

        if idx <= length // 2:
            answer += idx
        else:
            answer += length - idx

        queue.rotate(-idx)
        queue.popleft()

    return answer


n, m = map(int, input().split())
target = list(map(int, input().split()))

result = solution(target, n)
print(result)
