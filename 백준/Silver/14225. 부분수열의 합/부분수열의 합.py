import itertools
import sys


def solution(arr):
    answer = -1

    result = []

    for i in range(1, len(arr) + 1):
        combine = itertools.combinations(arr, i)
        for comb in combine:
            result.append(sum(comb))

    result = list(set(result))
    result.sort()

    num = 1
    idx = 0
    while True:
        try:
            if result[idx] != num:
                return num
            num += 1
            idx += 1
        except:
            return num


n = int(sys.stdin.readline().rstrip())
arr = list(map(int, sys.stdin.readline().split()))

print(solution(arr))
