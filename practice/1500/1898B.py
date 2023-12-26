import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    res = 0
    for i in range(n - 2, -1, -1):
        if a[i] <= a[i + 1]:
            continue
        q, r = divmod(a[i], a[i + 1])
        if r == 0:
            a[i] = a[i + 1]
            res += q - 1
        else:
            a[i] = a[i] // (q + 1)
            res += q
    print(res)


for _ in range(int(input())):
    solve()
