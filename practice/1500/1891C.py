import sys
from collections import deque

input = sys.stdin.readline


def solve():
    n = int(input())
    a = sorted(list(map(int, input().split())))
    x = 0
    i = 0
    j = n - 1
    res = 0
    while i <= j:
        x += a[i]
        if i == j and x == 1:
            print(res + 1)
            return
        if i == j:
            print(res + x - x // 2 + 1)
            return
        if x == a[j]:
            res += a[j] + 1
            x = 0
            i += 1
            j -= 1
        elif x > a[j]:
            res += a[j] + 1
            a[i] = x - a[j]
            x = 0
            j -= 1
        else:
            i += 1
    print(res)


for _ in range(int(input())):
    solve()
