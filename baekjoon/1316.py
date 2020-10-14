import sys

n = int(sys.stdin.readline())

groupWordCount = 0

for i in range(n):
	isGroupWord = True
	chars = set()
	previos = ''
	for c in sys.stdin.readline().strip():
		if c in chars and previos != c:
			isGroupWord = False
			break

		chars.add(c)
		previos = c
	
	if isGroupWord:
		groupWordCount += 1

print(groupWordCount)