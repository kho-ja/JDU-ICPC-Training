
n = int(input()) // 2
dp = [[0] * (n * 9 + 1) for i in range(n + 1)]
dp[0][0] = 1
for x in range(1, n + 1):
    for s in range(0, x * 9 + 1):
        dp[x][s] = sum(dp[x-1][max(s-9, 0):s+1])

print(sum([x*x for x in dp[n]]))
