import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    res = [0]*n
    asort = sorted([(a[i], i) for i in range(n)], reverse=True)
    bsort = sorted(b)
    for i in range(x):
        val, id = asort[i]
        res[id] = bsort[x-i-1]
    j = 0
    for i in range(x, n):
        val, id = asort[i]
        res[id] = bsort[-1-j]
        j += 1
    count = 0
    for i in range(n):
        count += 1 if a[i] > res[i] else 0
    if count == x:
        print('YES')
        print(*res)
    else:
        print('NO')
