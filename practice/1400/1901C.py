import sys
from math import log2
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    mx, mn = max(a), min(a)
    res = []
    while mx != mn:
        mx = (mx + mn)//2
        res.append(mn)
    print(len(res))
    if len(res) <= n:
        print(*res)