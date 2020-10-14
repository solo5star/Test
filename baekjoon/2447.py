import sys

n = int(sys.stdin.readline())

def level(x, y, divider):
	divider //= 3
	while divider > 1:
		if (x // divider) % 3 == 1 and (y // divider) % 3 == 1:
			return divider
		else:
			divider //= 3
	
	return 1

def isMidpos(x, y, lv):
	return (x // lv) % 3 == 1 and (y // lv) % 3 == 1

for y in range(n):
	for x in range(n):
		lv = level(x, y, n)
		DoNotPrint = (x // lv) % 3 == 1 and (y // lv) % 3 == 1
		# print(level(x, y, n), end="")
		print("*" if not DoNotPrint else " ", end="")
	print()