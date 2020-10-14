import sys

s = sys.stdin.readline().strip().upper()
dic = {}
for c in range(s):
	if c in dic:
		dic[c] += 1
	else:
		dic[c] = 1

maxCount = 0
maxChar = '?'
for key, count in dic.items():
	if count == maxCount:
		maxChar = '?'
	elif count > maxCount:
		maxCount = count
		maxChar = key

print(maxChar)