import sys
from bisect import insort_right, bisect_right

input = sys.stdin.readline


def solve():
    n = int(input())
    a = [0] * n
    for i in range(n):
        p, q = map(int, input().split())
        a[i] = (p, q)
    a.sort()
    res = []
    ans = 0
    for i in range(n):
        ans += bisect_right(res, -a[i][1])
        insort_right(res, -a[i][1])
    print(ans)


for _ in range(int(input())):
    solve()
