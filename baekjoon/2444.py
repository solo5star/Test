import sys

n = int(sys.stdin.readline())

for i in range(n):
	print(" " * (n - i) + "*" * (i * 2 - 1))

print("*" * (n * 2 - 1))

for i in range(1, n):
	print(" " * i + "*" * ((n - i) * 2 - 1))