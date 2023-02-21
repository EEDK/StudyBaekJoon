def Solution(num):
    answer = 0

    tmpList = [0]

    i = num
    while i > 0:
        if (num == i + eachNum(i)):
            tmpList.append(i)
        i -= 1

    print(tmpList[len(tmpList)-1])

    return answer


def eachNum(n):
    N = [int(i) for i in str(n)]

    return sum(N)



number = int(input(''))
Solution(number)