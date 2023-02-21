def solution(today, terms, privacies):
    answer = []

    termsDict = {}

    for term in terms:
        termType, termMonth = term.split()
        termsDict[termType] = termMonth

    i = 1
    for privacy in privacies:
        priDate, termType = privacy.split()

        print(diffMonth(priDate, today))

        if diffMonth(today, priDate) >= int(termsDict[termType]):
            answer.append(i)

        i += 1

    return answer


def diffMonth(nowDate, beforeDate):
    nowYear, nowMonth, nowDate = map(int, nowDate.split('.'))
    beforeYear, beforeMonth, beforeDate = map(int, beforeDate.split('.'))

    nowALL = nowDate + nowMonth * 28 + nowYear * 12 * 28
    beforeALL = beforeDate + beforeMonth * 28 + beforeYear * 12 * 28

    return (nowALL - beforeALL) / 28
