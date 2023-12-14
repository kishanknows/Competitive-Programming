import sys

input = sys.stdin.readline
res = []


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    if max(a) <= 0:
        print(n - 1)
        for i in range(n - 1, 0, -1):
            print(i, i + 1)
        return
    mx = max(a)
    id = a.index(mx)
    for i in range(5):
        res.append((id + 1, id + 1))
    if n > 1:
        res.append((2, id + 1))
        res.append((2, id + 1))
        for i in range(3, n + 1):
            res.append((i, i - 1))
            res.append((i, i - 1))
    print(len(res))
    for i, j in res:
        print(i, j)
    res.clear()


for _ in range(int(input())):
    solve()
