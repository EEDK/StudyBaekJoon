import sys


def solution(sangGen, numCard):
    answer = []

    dict = {}
    for card in sangGen:
        try:
            dict[card] += 1
        except:
            dict[card] = 1

    for card in numCard:
        try:
            if dict[card]:
                answer.append(1)
        except:
            answer.append(0)

    return answer


def printArr(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")


n = int(sys.stdin.readline())
arr1 = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
arr2 = list(map(int, sys.stdin.readline().split()))

answer = solution(arr1, arr2)
printArr(answer)
