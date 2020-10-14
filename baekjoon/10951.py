import sys

while True:
	try:
		print(sum(map(int, sys.stdin.readline().split())))
	except:
		break
