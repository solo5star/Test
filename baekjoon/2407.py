from sys import stdin

n, m = map(int, stdin.readline().split(' '))

result = 1
for i in range(m):
    result *= n - i
    result //= i + 1

print(result)
