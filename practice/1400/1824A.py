import sys

input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    seats = [0] * m
    r = 0
    l = 0
    for p in a:
        if p == -2:
            r += 1
        elif p == -1:
            l += 1
        else:
            seats[p - 1] = 1
    if r == 0 or l == 0:
        print(min(r + l + sum(seats), m))
        return
    val = 0
    post = [0] * m
    pre = [0] * m
    for i, k in enumerate(seats):
        val += k
        pre[i] = val
    val = 0
    for i in range(m - 1, -1, -1):
        val += seats[i]
        post[i] = val
    res = 0
    res = max(res, min(r + post[0], m))
    res = max(res, min(l + pre[m - 1], m))
    for i in range(1, m - 1):
        if seats[i] != 1:
            continue
        res = max(res, min(l + pre[i - 1], i) + min(r + post[i], m - i))
    print(res)


for _ in range(int(input())):
    solve()
