import sys

num_mapper = {}

for chars, value in {
	'ABC': 2,
	'DEF': 3,
	'GHI': 4,
	'JKL': 5,
	'MNO': 6,
	'PQRS': 7,
	'TUV': 8,
	'WXYZ': 9
}.items():
	for c in chars:
		num_mapper[c] = value

seconds = 0
for c in sys.stdin.readline().strip():
	seconds += 1 + num_mapper[c]

print(seconds)