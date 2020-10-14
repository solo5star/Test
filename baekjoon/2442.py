import sys

n = int(sys.stdin.readline())

for i in range(n):
	print(" " * (n - i - 1) + "*" * ((i + 1) * 2 - 1))