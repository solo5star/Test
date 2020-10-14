import sys

n = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
_min = nums[0]
_max = nums[0]
for i in range(n):
	if nums[i] < _min:
		_min = nums[i]
	if nums[i] > _max:
		_max = nums[i]

print(_min, _max)