memo = set(range(10000))

def d(n):
	selfNum = n
	while n > 0:
		selfNum += n % 10
		n //= 10
	
	return selfNum

for i in range(10000):
	memo.discard(d(i))

for i in memo:
	print(i)