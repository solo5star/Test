import sys

n, m = map(int, sys.stdin.readline().split(" "))

a = (n // (10 * m)) * 10
b = n % (a * m) if a > 0 else n

print(a)
print(b)
