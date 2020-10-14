import sys

n = int(sys.stdin.readline())

for i in range(n):
	print("*" * (i + 1) + " " * ((n - i - 1) * 2) + "*" * (i + 1))

for i in range(1, n):
	print("*" * (n - i) + " " * (i * 2) + "*" * (n - i))