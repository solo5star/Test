import sys

n = int(sys.stdin.readline())

# 숫자 0 = None
# 숫자 1 = 0
dp = [None, 0]

# Bottom Up 구현
for i in range(2, n + 1):
	# Case 1 - 이전 숫자 + 1
	dp.append(dp[i - 1] + 1)

	# Case 2 - 2로 나눌 수 있는지
	# 1을 빼는 것이 유리한지
	# 2로 나누는 것이 유리한지 비교
	if i % 2 == 0:
		dp[i] = min(dp[i], dp[i // 2] + 1)
	
	# Case 3 - 3으로 나눌 수 있는지
	if i % 3 == 0:
		dp[i] = min(dp[i], dp[i // 3] + 1)

print(dp[n])