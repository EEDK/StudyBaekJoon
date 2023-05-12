import sys


def solution(num):
    fib = [0, 1]

    while fib[-1] < num:
        fib.append(fib[-1] + fib[-2])

    result = []
    for i in range(len(fib) - 1, 0, -1):
        if fib[i] <= num:
            result.append(fib[i])
            num -= fib[i]
            if num == 0:
                break

    result.sort()
    return result


n = int(sys.stdin.readline().rstrip())
arr = []
for _ in range(n):
    tmp = int(sys.stdin.readline().rstrip())
    arr.append(tmp)

for i in range(n):
    result = solution(arr[i])
    print(" ".join(map(str, result)))
