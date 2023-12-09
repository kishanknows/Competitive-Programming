import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    suf = [0] * (n+1)
    for i in range(n-1, -1, -1):
        suf[i] = suf[i+1] + a[i]
    res = suf[0] + sum(suf[i] for i in range(1, n) if suf[i] > 0)
    print(res)