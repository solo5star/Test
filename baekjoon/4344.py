import sys

n = int(sys.stdin.readline())

for i in range(n):
	test = list(map(int, sys.stdin.readline().split()))
	avg = sum(test[1:]) / test[0]
	overHalf = 0
	for score in test[1:]:
		if score > avg:
			overHalf += 1
	
	print("{:0.3f}%".format((overHalf / test[0]) * 100))