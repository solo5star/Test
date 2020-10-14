n = int(input())
for i in range(n):
	print("Case #" + str(i + 1) + ": " + str(sum(map(int, input().split()))))