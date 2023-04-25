def solution(unlistens, unknowns):
    unlistenKnown = set(unlistens).intersection(set(unknowns))

    return list(unlistenKnown)


n, m = map(int, input().split())

# 첫 번째 배열
arr1 = []
for i in range(n):
    arr1.append(input())

# 두 번째 배열
arr2 = []
for i in range(m):
    arr2.append(input())

answer = solution(arr1, arr2)
answer.sort()
print(len(answer))
for person in answer:
    print(person)
