import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print(a[0])
        return
    mx = max(a[1:])
    mxid = a.index(mx)
    if mxid == n - 1 and a[mxid - 1] < a[0]:
        res = [mx] + a[:mxid]
        print(*res)
        return
    res = a[mxid:]
    res.append(a[mxid - 1])
    i = mxid - 2
    while i >= 0 and a[0] < a[i]:
        res.append(a[i])
        i -= 1
    res = res + a[: i + 1]
    print(*res)


for _ in range(int(input())):
    solve()
