
def solution(lst, money):
    answer = 0

    leng = len(lst) - 1
    nowDigit = lst[leng]

    while money > 0 and leng >= 0:
        nowDigit = lst[leng]
        if money - nowDigit < 0:
            leng -= 1

        else:
            money -= nowDigit
            answer += 1

    return answer


n, money = map(int, input().split())
lst = [int(input()) for _ in range(n)]

print(solution(lst, money))
