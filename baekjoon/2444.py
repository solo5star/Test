import sys

n = int(sys.stdin.readline())

for i in range(1, 2 * n):
	if i < n:
		print(" " * (n - i) + "*" * (i * 2 - 1))
	else:
		print(" " * (i - n) + "*" * ((2*n-i) * 2 - 1))