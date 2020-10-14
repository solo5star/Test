import sys

row, col = map(int, sys.stdin.readline().split())

strlist = []
dupcheck = set()
count = 0

for i in range(row):
	strlist.append(sys.stdin.readline().strip())

for i in range(len(strlist[0])):
	colstr = []
	for j in range(len(strlist)):
		colstr.append(strlist[j][i])

	colstr = ''.join(colstr)
	dupcheck.add(colstr)

def cycle():
	global dupcheck
	global count
	_dupcheck = set()
	for colstr in dupcheck:
		colstr = colstr[1:]

		if colstr in _dupcheck:
			return False
		
		_dupcheck.add(colstr)
	
	count += 1
	dupcheck = _dupcheck
	return True

while True:
	# remove first row
	strlist.pop(0)

	if len(strlist) == 0:
		break

	if cycle() == False:
		break

print(count)
