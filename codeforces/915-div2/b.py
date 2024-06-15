import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    mp = {}
    for _ in range(n - 1):
        u, v = map(int, input().split())
        if u in mp:
            mp[u] += 1
        else:
            mp[u] = 1
        if v in mp:
            mp[v] += 1
        else:
            mp[v] = 1
    res = 0
    for value in mp.values():
        if value == 1:
            res += 1
    res = res // 2 + 1 if res & 1 else res // 2
    print(res)


for _ in range(int(input())):
    solve()
