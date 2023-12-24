import sys

input = sys.stdin.readline


def solve():
    n, k, d = map(int, input().split())
    a = list(map(int, input().split()))
    v = list(map(int, input().split()))
    b = [i + 1 - a[i] for i in range(n)]
    res = 0
    t = 0
    ops = 0
    while ops < 2 * n + 1 and ops < d:
        res = max(res, b.count(0) + (d - ops - 1) // 2)
        for i in range(v[t]):
            b[i] -= 1
        t += 1
        t = t % k
        ops += 1
    print(res)


for _ in range(int(input())):
    solve()
