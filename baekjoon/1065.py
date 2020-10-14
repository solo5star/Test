import sys

def d(n):
	if n < 100:
		return True
	else:
		gap = n % 10 - ((n // 10) % 10)
		while True:
			previos = n % 10
			n //= 10
			current = n % 10
			if n == 0:
				break
			if gap != previos - current:
				return False
		
		return True


count = 0
for i in range(1, int(sys.stdin.readline()) + 1):
	if d(i):
		count += 1

print(count)

