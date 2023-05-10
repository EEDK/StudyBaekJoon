import itertools


def solution(n, m):

    num = []
    for i in range(1, n+1):
        num.append(i)

    tmp = itertools.permutations(num, m)

    for case in tmp:
        printTuple(case)


def printTuple(tu):

    for s in tu:
        print(s, end=" ")
    print()


n, m = map(int, input('').split())
solution(n, m)
