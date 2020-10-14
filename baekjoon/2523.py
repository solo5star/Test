import sys

n = int(sys.stdin.readline())

for i in range(1, 2 * n):
	if i < n:
		print("*" * i)
	else:
		print("*" * (2 * n - i))