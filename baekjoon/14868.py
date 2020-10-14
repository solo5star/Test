import sys

size, count = map(int, sys.stdin.readline().split())

world = [[0 for j in range(size)] for i in range(size)]

parents = {}

def find(a):
	if a not in parents:
		parents[a] = a
		return a
	elif parents[a] == a:
		return a
	else:
		return find(parents[a])

def union(a, b):
	a = find(a)
	b = find(b)
	if a != b:
		parents[b] = a

def checkAllUnioned():
	compare = parents[1]
	for cultureId in parents:
		if compare != find(cultureId):
			return False
	
	return True

def getAdjacent(x, y):
	width = len(world)
	height = len(world[0])

	ret = []
	if x > 0:
		ret.append((x - 1, y))
	if x < width - 1:
		ret.append((x + 1, y))
	if y > 0:
		ret.append((x, y - 1))
	if y < height - 1:
		ret.append((x, y + 1))

	return ret

def getCoords():
	ret = []
	for y in range(len(world)):
		for x in range(len(world[0])):
			if world[y][x] != 0:
				ret.append((x, y))
	
	return ret

def spread():
	for x, y in getCoords():
		for _x, _y in getAdjacent(x, y):
			# spread culture
			if world[_y][_x] == world[y][x]:
				continue

			elif world[_y][_x] == 0:
				# find empty tile! spread
				world[_y][_x] = world[y][x]

				for __x, __y in getAdjacent(_x, _y):
					# search adjacent
					if world[__y][__x]:
						# find adjacent! union us
						union(world[_y][_x], world[__y][__x])

for i in range(count):
	x, y = map(int, sys.stdin.readline().strip().split())
	# id of culture
	world[y - 1][x - 1] = i + 1

yearElappsed = 0
while True:
	spread()
	yearElappsed += 1

	if checkAllUnioned():
		print(yearElappsed)
		break