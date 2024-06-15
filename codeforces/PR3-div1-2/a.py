import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    count = [False] * 4
    for _ in range(n):
        x, y = map(int, input().split())
        if x < 0:
            count[0] = True
        if x > 0:
            count[1] = True
        if y < 0:
            count[2] = True
        if y > 0:
            count[3] = True
    if False in count:
        print("YES")
    else:
        print("NO")


for _ in range(int(input())):
    solve()
