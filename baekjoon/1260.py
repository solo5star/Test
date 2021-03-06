import sys

n, m, v = map(int, sys.stdin.readline().split())

graph = {}

graph[v] = [v]

for i in range(m):
	v1, v2 = map(int, sys.stdin.readline().split())
	if v1 in graph:
		graph[v1].append(v2)
	else:
		graph[v1] = [v2]
	
	if v2 in graph:
		graph[v2].append(v1)
	else:
		graph[v2] = [v1]

for i in graph:
	graph[i].sort()

dfs_result = []
dfs_visited = set()

def dfs(v):
	dfs_result.append(v)
	dfs_visited.add(v)
	for _v in graph[v]:
		if _v in dfs_visited:
			continue
		else:
			dfs(_v)

bfs_result = []
bfs_visited = set()
bfs_queue = []

def bfs(v):
	bfs_result.append(v)
	bfs_visited.add(v)
	for _v in graph[v]:
		if _v in bfs_visited:
			continue
		else:
			bfs_queue.append(_v)
			# prevent queue duplicate
			bfs_visited.add(_v)

dfs(v)
bfs(v)

while len(bfs_queue) > 0:
	bfs(bfs_queue.pop(0))

print(' '.join(map(str, dfs_result)))
print(' '.join(map(str, bfs_result)))