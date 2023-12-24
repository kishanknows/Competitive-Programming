import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    l = sorted(list(map(int, input().split())))
    r = sorted(list(map(int, input().split())))
    c = sorted(list(map(int, input().split())), reverse=True)
    d = sorted([r[i] - l[i] for i in range(n)])
    res = sum([c[i] * d[i] for i in range(n)])
    print(res)


for _ in range(int(input())):
    solve()
