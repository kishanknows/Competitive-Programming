import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    mn = 10**9
    mnwin = 10**9
    res = 0
    for i in range(n):
        if a[i] < mn:
            mn = a[i]
        elif a[i] < mnwin:
            res += 1
            mnwin = a[i]
    print(res)


for _ in range(int(input())):
    solve()
