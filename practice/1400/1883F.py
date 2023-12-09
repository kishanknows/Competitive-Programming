import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    suff = [0]*n
    s = set()
    for i in range(n-1, -1, -1):
        s.add(a[i])
        suff[i] = len(s)
    res = 0
    for i in range(n):
        if a[i] not in s:
            continue
        res += suff[i]
        s.remove(a[i])
    print(res)

for _ in range(int(input())):
    solve()