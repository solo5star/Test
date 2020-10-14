import sys

n = int(sys.stdin.readline())
for i in range(n):
	count, s = sys.stdin.readline().strip().split()
	print(''.join([c * int(count) for c in s]))