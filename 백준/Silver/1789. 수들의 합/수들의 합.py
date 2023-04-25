import sys
import math

N = int(sys.stdin.readline())


def solution(N):
    return int((-1 + math.sqrt(1 + 8 * N)) // 2)


print(solution(N))
