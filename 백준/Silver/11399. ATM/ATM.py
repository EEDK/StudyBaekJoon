def solution(person):

    waitTime = 0
    result = []

    person.sort()

    i = 0
    for per in person:
        waitTime += per
        result.append(waitTime)

    return sum(result)


n = int(input(''))
workTime = list(map(int, input().split()))

print(solution(workTime))
