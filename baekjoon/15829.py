import sys

n = int(sys.stdin.readline())

text = sys.stdin.readline()

acc = 0
for i in range(n):
    acc += (ord(text[i]) - ord('a') + 1) * (31 ** i) % 1234567891
    acc %= 1234567891

print(acc)
