def solution(a, b, c, d):

    countX = 0
    countY = 0

    for i in range(0, a, c+1):
        countX += 1
    for j in range(0, b, d+1):
        countY += 1

    return countX * countY


if __name__ == '__main__':
    a, b, c, d = map(int, input().split())
    print(solution(a, b, c, d))
