import sys

print(max(list(map(int, sys.stdin.readline().strip()[::-1].split()))))