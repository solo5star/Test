import sys

s = sys.stdin.readline().strip()

print(' '.join([str(s.find(chr(code))) for code in range(ord('a'), ord('z') + 1)]))