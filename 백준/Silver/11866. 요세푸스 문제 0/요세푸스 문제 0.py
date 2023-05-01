from collections import deque


def solution(n, m):
    q = deque(range(1, n+1))
    res = []
    while q:
        # k-1번째까지는 모두 뒤로 이동시킴
        for _ in range(m-1):
            q.append(q.popleft())
        # k번째 요소를 결과 리스트에 추가하고 큐에서 삭제
        res.append(q.popleft())
    return res


n, m = map(int, input().split(" "))
arr = (solution(n, m))

print("<", end="")
for i in range(len(arr)):
    if i < len(arr) - 1:
        print(arr[i], end=", ")
    else:
        print(arr[i], end="")

print(">")
