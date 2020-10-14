h, m = list(map(int, input().split()))

if(m >= 45):
	print(h, m - 45)
else:
	print((h + 23) % 24, m + 15)