import sys

print(len(set([int(sys.stdin.readline()) % 42 for i in range(10)])))