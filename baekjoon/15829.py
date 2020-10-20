import sys

n = int(sys.stdin.readline())
s = sys.stdin.readline().strip()

dp = [1, 31]
for i in range(2, n+1):
    dp.append(dp[i - 1] * 31);

result = 0
for i in range(n):
    result += (ord(s[i]) - ord('a') + 1) * dp[i]
    
result %= 1234567891

print(result)
