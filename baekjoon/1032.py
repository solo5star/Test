import sys

n = int(sys.stdin.readline())

strings = [sys.stdin.readline() for i in range(n)]

for i in range(len(strings[0])):
    if all(strings[0][i] == s[i] for s in strings):
        print(strings[0][i], end='')
    else:
        print('?', end='')
