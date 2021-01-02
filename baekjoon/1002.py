import sys

def dist(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

n = int(sys.stdin.readline())

for i in range(n):
    x1, y1, r1, x2, y2, r2 = map(int, sys.stdin.readline().split(' '))

    distance = dist(x1, y1, x2, y2)

    if x1 == x2 and y1 == y2:
        if r1 == r2:
            print(-1)
        else:
            print(0)
    elif distance == r1 + r2:
        print(1)
    elif distance < r1 + r2:
        print(2)
    elif distance > r1 + r2:
        print(0)
    else:
        print(-1)
