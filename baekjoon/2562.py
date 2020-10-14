import sys

_max = 0
_maxIndex = 1
for i in range(1, 10):
	n = int(sys.stdin.readline())
	if n > _max:
		_max = n
		_maxIndex = i

print(_max, _maxIndex)