import sys

input = sys.stdin.readline


def solve():
    a, b, c = map(int, input().split())
    if a == b:
        print(c)
    elif b == c:
        print(a)
    else:
        print(b)


for _ in range(int(input())):
    solve()
