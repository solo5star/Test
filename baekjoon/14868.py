import sys

n, k = map(int, sys.stdin.readline().split())

points = []

for i in range(k):
	points.append(sum(map(int, sys.stdin.readline().split())))

points.sort()

m = 0
for i in range(k):
	if i == 0:
		continue

	diff = points[i] - points[i - 1]
	if m < diff:
		m = diff

print(m // 2)