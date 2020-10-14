import sys

n = int(sys.stdin.readline())

for i in range(n):
	print(" " * i + "*" * ((n - i) * 2 - 1))

for i in range(1, n):
	print(" " * (n - i - 1) + "*" * (i * 2 + 1))