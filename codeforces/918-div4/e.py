import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n):
        if i & 1:
            a[i] = -a[i]
    # print(a)
    sm = 0
    mp = set()
    res = "NO"
    pre = []
    for i in range(n):
        sm += a[i]
        if sm in mp or sm == 0:
            res = "YES"
            break
        mp.add(sm)
    print(res)


for _ in range(int(input())):
    solve()
