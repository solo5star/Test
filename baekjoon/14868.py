import sys

size, count = map(int, sys.stdin.readline().split())

world = [[0 for j in range(size)] for i in range(size)]
world_spreaded = [[0 for j in range(size)] for i in range(size)]

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

def spread(nextCoords):
	_nextCoords = []
	for x, y in nextCoords:
		for _x, _y in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]:
			# Out of bound
			if(_x < 0 or _y < 0 or _x >= size or _y >= size):
				continue

			# spread culture
			if world[_y][_x] == world[y][x]:
				continue

			elif world[_y][_x] == 0:
				# find empty tile! spread
				world[_y][_x] = world[y][x]
				# .. and spread next loop
				if world_spreaded[_y][_x] == 0:
					_nextCoords.append((_x, _y))
					world_spreaded[_y][_x] = 0

				for __x, __y in [(_x - 1, _y), (_x + 1, _y), (_x, _y - 1), (_x, _y + 1)]:
					# Out of bound
					if(__x < 0 or __y < 0 or __x >= size or __y >= size):
						continue

					if world[__y][__x] != 0:
						# find adjacent! union us
						union(world[_y][_x], world[__y][__x])
	
	return _nextCoords

# def printWorld(world):
# 	print("----------")
# 	for row in world:
# 		print(row)

# 	print("----------")
# 	print(parents)
# 	print("----------")
# 	input()

def solution():
	nextCoords = []
	yearElappsed = 0

	# Initialize world
	for i in range(count):
		x, y = map(int, sys.stdin.readline().strip().split())
		x, y = x - 1, y - 1
		# id of culture
		world[y][x] = i + 1
		# spread next year
		nextCoords.append((x, y))

	while True:
		nextCoords = spread(nextCoords)
		yearElappsed += 1

		# printWorld(world)

		if checkAllUnioned():
			print(yearElappsed)
			break

solution()