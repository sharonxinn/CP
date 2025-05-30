n = int(input())
plants = []
for _ in range(n):
    d, t = map(int, input().split())
    plants.append((d, t))

plants.sort(key=lambda x: (-x[0], -x[1]))

max_time = 2000 + 1  
dp = [float('inf')] * (max_time + 1)
dp[0] = 0 

for d, t in plants:
    new_dp = [float('inf')] * (max_time + 1)
    for time in range(max_time + 1):
        if dp[time] != float('inf'):
            if time == 0:
                new_time = t
                new_damage = dp[time] + d
            else:
                new_time = time - 1 + t
                new_damage = dp[time]
            if new_time > max_time:
                new_time = max_time
            if new_damage < new_dp[new_time]:
                new_dp[new_time] = new_damage
            if dp[time] < new_dp[time]:
                new_dp[time] = dp[time]
    dp = new_dp

print(min(dp))