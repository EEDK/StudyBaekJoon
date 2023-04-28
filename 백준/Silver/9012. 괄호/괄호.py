import sys


def isPS(arr):
    answer = True

    lst = []

    for str in arr:
        if str == '(':
            lst.append(str)
        else:
            if len(lst) < 1:
                answer = False
                break
            else:
                tmp = lst.pop()

    if len(lst) > 0:
        answer = False

    return answer


n = int(input())  # 문자열의 개수를 입력받습니다.
strings = []  # 문자열들을 저장할 리스트를 초기화합니다.

for i in range(n):
    string = input()  # 문자열을 입력받습니다.
    strings.append(string)  # 리스트에 문자열을 추가합니다.

for string in strings:
    if isPS(string):
        print('YES')
    else:
        print('NO')
