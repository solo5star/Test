n = int(input())
c3 = 0
c5 = 0
result = -1;
for i in range(0, 5):
	if(n % 5 == 0):
		c5 = n // 5
		result = c3 + c5
		break
	n -= 3
	c3 += 1

print(result)
