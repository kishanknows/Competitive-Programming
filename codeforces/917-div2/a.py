import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    if 0 in a:
        print(0)
        return
    count = 0
    for num in a:
        if num < 0:
            count += 1
    if count & 1:
        print(0)
        return
    print(1)
    print(1, 0)


for _ in range(int(input())):
    solve()
