n, x = map(int, input().split())
first = True
for a in map(int, input().split()):
	if a < x:
		if first:
			print(a, end='')
			first = False
		else:
			print(' ' + str(a), end='')