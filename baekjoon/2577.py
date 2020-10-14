import sys

n1 = int(sys.stdin.readline())
n2 = int(sys.stdin.readline())
n3 = int(sys.stdin.readline())
y = n1 * n2 * n3

counts = [0 for i in range(10)]

while y != 0:
	counts[y % 10] += 1
	y //= 10

for c in counts:
	print(c)