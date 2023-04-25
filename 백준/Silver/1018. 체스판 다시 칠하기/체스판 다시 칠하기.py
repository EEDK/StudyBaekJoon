n, m = map(int, input().split())

# 보드 입력 받기
board = []
for i in range(n):
    row = input().strip()
    board.append(row)

# 8x8 체스판 패턴 만들기
patterns = ['BWBWBWBW', 'WBWBWBWB'] * 4

# 체스판 패턴과 비교하여 다른 부분 카운트하기
min_count = n * m
for i in range(n - 7):
    for j in range(m - 7):
        count1, count2 = 0, 0
        for k in range(8):
            for l in range(8):
                # 체스판 패턴과 일치하지 않는 경우
                if board[i+k][j+l] != patterns[k][l]:
                    count1 += 1
                if board[i+k][j+l] != patterns[1-k][l]:
                    count2 += 1
        # 현재 패턴에서 다시 칠해야 하는 칸의 최소 개수
        min_count = min(min_count, count1, count2)

print(min_count)
