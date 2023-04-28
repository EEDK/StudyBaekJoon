def solution(strings):
    strings = set(strings)
    strings = list(strings)

    strings = sorted(strings, key=lambda x: (len(x), x))
    for s in strings:
        print(s)


n = int(input())  # 문자열의 개수를 입력받습니다.
strings = []  # 문자열들을 저장할 리스트를 초기화합니다.

for i in range(n):
    string = input()  # 문자열을 입력받습니다.
    strings.append(string)  # 리스트에 문자열을 추가합니다.

solution(strings)
