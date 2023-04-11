def solution(numbers):
    answer = [-1] * len(numbers)  # answer 배열을 -1로 초기화
    stack = []  # 스택 초기화

    for i in range(len(numbers)):
        while stack and numbers[stack[-1]] < numbers[i]:  # 스택의 top과 현재 숫자를 비교
            top = stack.pop()
            answer[top] = numbers[i]  # top의 뒷 큰수를 현재 숫자로 갱신

        stack.append(i)  # 현재 숫자의 인덱스를 스택에 추가

    return answer
