def tsp_dp(n, W):
    maximum = 10000001

    dp = [[0] * (1 << n) for _ in range(n)]
    for i in range(n):
        for j in range(1 << n):
            dp[i][j] = maximum

    dp[0][1] = 0

    for visit in range(1, (1 << n)):
        for cur in range(n):
            if visit & (1 << cur) == 0:
                continue
            for nxt in range(n):
                if visit & (1 << nxt) != 0 or W[cur][nxt] == 0:
                    continue
                dp[nxt][visit | (1 << nxt)] = min(
                    dp[nxt][visit | (1 << nxt)], dp[cur][visit] + W[cur][nxt])

    min_cost = maximum
    for i in range(1, n):
        if W[i][0] != 0:
            min_cost = min(min_cost, dp[i][(1 << n) - 1] + W[i][0])

    return min_cost


n = int(input())
W = []
for _ in range(n):
    W.append(list(map(int, input().split())))

result = tsp_dp(n, W)
print(result)
