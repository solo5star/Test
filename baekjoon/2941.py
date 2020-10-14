import sys

a = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
s = sys.stdin.readline().strip()

for c in a:
	s = s.replace(c, '0')

print(len(s))