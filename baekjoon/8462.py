import sys

n, t = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))

for i in range(t):
	start, end = map(int, sys.stdin.readline().split())

	d = {}

	for n in nums[start-1:end]:
		if n in d:
			d[n] += 1
		else:
			d[n] = 1
	
	total = 0
	for n in d:
		total += d[n] * d[n] * n
	
	print(total)