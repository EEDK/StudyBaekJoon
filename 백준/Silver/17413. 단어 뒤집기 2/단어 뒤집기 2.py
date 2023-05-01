import sys

s = sys.stdin.readline().strip()

stack = []
flag = False

for c in s:
    if c == '<':
        while stack:
            print(stack.pop(), end='')
        flag = True
        print('<', end='')
    elif c == '>':
        flag = False
        print('>', end='')
    elif flag:
        print(c, end='')
    elif c == ' ':
        while stack:
            print(stack.pop(), end='')
        print(' ', end='')
    else:
        stack.append(c)

while stack:
    print(stack.pop(), end='')
