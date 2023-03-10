def solution(brown, yellow):
    answer = []

    lst = []
    total = brown + yellow

    for w in range(3, total):
        if total % w == 0:
            lst.append([w, total // w])

    for exam in lst:
        if (exam[0] - 2) * (exam[1] - 2) == yellow:
            answer = exam

    return answer

