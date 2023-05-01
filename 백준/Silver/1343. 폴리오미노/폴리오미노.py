from collections import deque


def solution(str):
    answer = ''

    queue = deque()

    for i in range(len(str)):
        if str[i] == 'X':
            queue.append(str[i])
        elif str[i] == '.':
            length = len(queue)
            if length % 2 == 1:
                return -1
            ACnt = 0
            BCnt = 0
            while length >= 4:
                ACnt += 1
                length -= 4
            if length != 0:
                BCnt += 1

            answer += 'AAAA' * ACnt
            answer += 'BB' * BCnt
            answer += '.'

            while queue:
                tmp = queue.popleft()

    length = len(queue)
    if length % 2 == 1:
        return -1
    ACnt = 0
    BCnt = 0
    while length >= 4:
        ACnt += 1
        length -= 4
    if length != 0:
        BCnt += 1
    while queue:
        tmp = queue.popleft()
    answer += 'AAAA' * ACnt
    answer += 'BB' * BCnt

    return answer


polyoMino = input('')
print(solution(polyoMino))
