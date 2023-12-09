import sys
input = sys.stdin.readline

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    i = n-1; vis = set()
    while i not in vis and len(vis) < k:
        vis.add(i)
        if a[i] > n:
            print('NO')
            return
        i = i - a[i]
        if i < 0: i += n
    print('YES')
for _ in range(int(input())):
    solve()
