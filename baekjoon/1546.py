import sys

length = int(sys.stdin.readline())
scores = list(map(int, sys.stdin.readline().split()))
_max = max(scores)
scores = [score / _max * 100 for score in scores]
print(sum(scores) / length)