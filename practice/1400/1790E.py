import sys

input = sys.stdin.readline


def solve():
    x = int(input())
    a = x
    b = 0
    for i in range(32, -1, -1):
        if x & (1 << i):
            continue
        if 2 * x - (a + b) >= (1 << (i + 1)):
            a += 1 << i
            b += 1 << i
    if (a + b) == 2 * x:
        print(a, b)
    else:
        print(-1)


for _ in range(int(input())):
    solve()
