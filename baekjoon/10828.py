import sys

n = int(sys.stdin.readline())

stack = []

for i in range(n):
	inst = sys.stdin.readline().strip().split()
	
	if inst[0] == "push":
		stack.append(inst[1])
	elif inst[0] == "top":
		print(stack[-1] if len(stack) > 0 else -1)
	elif inst[0] == "size":
		print(len(stack))
	elif inst[0] == "empty":
		print(1 if len(stack) == 0 else 0)
	elif inst[0] == "pop":
		print(stack.pop() if len(stack) > 0 else -1)