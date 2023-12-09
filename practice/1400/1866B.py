import sys
input = sys.stdin.readline

mod = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    m = int(input())
    c = list(map(int, input().split()))
    d = list(map(int, input().split()))

    count = {}
    res = 1

    for i in range(n):
        count[a[i]] = b[i]
    for i in range(m):
        if c[i] not in count:
            print(0)
            return
        count[c[i]] -= d[i]
        if count[c[i]] < 0:
            print(0)
            return
    for value in count.values():
        if value > 0:
            res = (res * 2) % mod
    print(res)

# for _ in range(int(input())):
solve()