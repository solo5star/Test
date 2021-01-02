import sys

n = int(sys.stdin.readline())

for i in range(n):
    x1, y1, r1, x2, y2, r2 = map(int, sys.stdin.readline().split(' '))

    distanceSquared = (x1 - x2) ** 2 + (y1 - y2) ** 2
    radiusDiffSquared = (r1 - r2) ** 2
    radiusExtendedSquared = (r1 + r2) ** 2

    # 원의 중심이 같을 때
    if x1 == x2 and y1 == y2:
        if r1 == r2:
            print(-1)
        else:
            print(0)
            
    # 원이 내접할 때
    elif distanceSquared == radiusDiffSquared:
        print(1)
        
    # 원이 원을 포함할 때
    elif distanceSquared < radiusDiffSquared:
        print(0)

    # 원이 외접할 때
    elif distanceSquared == radiusExtendedSquared:
        print(1)

    # 원이 원 밖에 있으며 접하지 않을 때
    elif distanceSquared > radiusExtendedSquared:
        print(0)

    # 원이 원과 두 점으로 접할 때
    elif distanceSquared < radiusExtendedSquared:
        print(2)
