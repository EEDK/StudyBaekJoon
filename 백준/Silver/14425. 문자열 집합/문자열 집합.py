def solution(sets, strings):
    answer = 0
    set_strings = set(sets)  # 집합 S를 생성

    for string in strings:
        if string in set_strings:  # 집합 S에 포함되어 있는지 확인
            answer += 1

    return answer


n, m = map(int, input().split())

set_strings = []
strings = []

for _ in range(n):
    word = input()
    set_strings.append(word)

for _ in range(m):
    word = input()
    strings.append(word)

print(solution(set_strings, strings))
