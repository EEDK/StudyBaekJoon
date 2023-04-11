def solution(numbers, target):
    answer = 0
    result = [0]

    for i in numbers:
        tmp = []
        for j in result:
            tmp.append(j + i)
            tmp.append(j - i)
        result = tmp

    for num in result:
        if num == target:
            answer += 1

    return answer
