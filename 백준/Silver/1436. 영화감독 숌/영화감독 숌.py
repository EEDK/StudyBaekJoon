import sys


def solution(number):
    i = 666
    cnt = 0

    while True:
        if isSSS(i):
            cnt += 1

        if cnt == number:
            break

        i += 1

    return i


def isSSS(num):
    tmpStr = str(num)
    if '666' in tmpStr:
        return True
    else:
        return False


n = int(sys.stdin.readline().rstrip())
print(solution(n))
