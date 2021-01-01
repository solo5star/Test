import sys

def fibonacci(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    if n == 2:
        return 1;

    n -= 2;

    a = 1
    b = 1
    current = 2;

    while n > 0:
        current = a + b
        a = b
        b = current
        n -= 1

    return current

print(fibonacci(int(sys.stdin.readline())))
