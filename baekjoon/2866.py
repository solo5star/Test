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
	for colstr in list(dupcheck):
		colstr = colstr[1:]

		if colstr in dupcheck:
			return False
		
		dupcheck.add(colstr)
	
	return True

while True:
	# remove first row
	strlist.pop(0)

	if cycle() == False:
		break

	count += 1

	if len(strlist) == 0:
		break

print(count)
