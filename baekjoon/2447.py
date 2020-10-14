import sys

n = int(sys.stdin.readline())

def level(x, y, divider):
	divider //= 3
	while True:
		if (x // divider) % 3 == 1 and (y // divider) % 3 == 1:
			return divider
		elif divider == 1:
			return divider
		else:
			return level(x, y, divider)

def isMidpos(x, y, lv):
	return (x // lv) % 3 == 1 and (y // lv) % 3 == 1

for y in range(n):
	for x in range(n):
		DoNotPrint = isMidpos(x, y, level(x, y, n))
		# print(level(x, y, n), end="")
		print("*" if not DoNotPrint else " ", end="")
	print()