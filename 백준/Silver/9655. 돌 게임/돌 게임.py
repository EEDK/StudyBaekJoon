def stoneGame(number):

    if number % 2 == 0:
        return 'CY'

    else:
        return 'SK'


n = int(input(''))
print(stoneGame(n))