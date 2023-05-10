from itertools import combinations


def solution(people):
    cases = combinations(people, 7)

    for case in cases:
        if sum(case) == 100:
            return case

    return -1


n = 9
arr = []

for i in range(n):
    tmp = int(input(''))
    arr.append(tmp)


answer = solution(arr)
tmp = list(answer)
tmp.sort()

for i in range(7):
    print(tmp[i])
