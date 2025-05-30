n = int(input())
prices = list(map(int, input().split()))
total = sum(prices)
max_sam = total // 2
dp = [False] * (max_sam + 1)
dp[0] = True

for price in prices:
    for j in range(max_sam, price - 1, -1):
        if dp[j - price]:
            dp[j] = True
result = 0
for j in range(max_sam, -1, -1):
    if dp[j]:
        result = j
        break

print(result)