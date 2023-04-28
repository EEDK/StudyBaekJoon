def solution(hour, minute, second, cookTime):
    while cookTime > 3600:
        cookTime -= 3600
        hour += 1
        if hour == 24:
            hour = 0
    while cookTime > 60:
        cookTime -= 60
        minute += 1
        if minute == 60:
            minute = 0
            hour += 1
            if hour == 24:
                hour = 0

    second += cookTime

    if second >= 60:
        second -= 60
        minute += 1
        if minute == 60:
            minute = 0
            hour += 1
            if hour == 24:
                hour = 0

    print(hour, end=" ")
    print(minute, end=" ")
    print(second, end=" ")



hour, minute, second = map(int, input().split())
targetSecond = int(input())

solution(hour, minute, second, targetSecond)
