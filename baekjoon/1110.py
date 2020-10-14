n = int(input())
tmp = n
c = 0

while True:
	c += 1
	n1 = tmp % 10
	n10 = tmp // 10
	tmp = ((n10 + n1) % 10) + (n1 * 10)
	if tmp == n:
		print(c)
		break