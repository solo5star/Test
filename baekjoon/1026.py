import sys

n = int(sys.stdin.readline())

a, b = [list(map(int, sys.stdin.readline().split(" "))) for i in range(2)]

a.sort()
b.sort(reverse=True)

acc = 0
for i in range(n):
    acc += a[i] * b[i]

print(acc)