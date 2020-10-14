import sys

n, m, v = map(int, sys.stdin.readline().split())

graph = {}
for i in range(1, n + 1):
	graph[i] = []

for i in range(m):
	v1, v2 = map(int, sys.stdin.readline().split())
	graph[v1].append(v2)
	graph[v2].append(v1)

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
	
	while len(bfs_queue) > 0:
		bfs(bfs_queue.pop(0))

dfs(v)
bfs(v)

print(' '.join(map(str, dfs_result)))
print(' '.join(map(str, bfs_result)))