import sys

n = int(sys.stdin.readline())
for i in range(n):
	score = 0
	acc = 0
	for c in sys.stdin.readline():
		if c == 'O':
			acc += 1
			score += acc
		else:
			acc = 0

	print(score)