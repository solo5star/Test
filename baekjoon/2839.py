n = int(input())
c3 = 0
c5 = 0
for i in range(0, 5):
	if(n % 5 == 0):
		c5 = n // 5
		print(c3 + c5)
		return
	n -= 3
	c3++

print(-1)
