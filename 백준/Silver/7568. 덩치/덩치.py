def solution(arr):
    answer = []

    for i in range(len(arr)):
        iWeight = arr[i][0]
        iHeight = arr[i][1]
        iCount = 1

        for j in range(len(arr)):
            jWeight = arr[j][0]
            jHeight = arr[j][1]

            if iWeight < arr[j][0] and iHeight < arr[j][1]:
                iCount += 1
        answer.append(iCount)

    return answer


n = int(input())
data = []
for i in range(n):
    a, b = map(int, input().split())
    data.append([a, b])

for score in solution(data):
    print(score, end=" ")
