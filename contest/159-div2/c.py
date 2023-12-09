import sys
import math
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print(1)
        continue
    b = set(a)
    mx = max(a)
    x = 0
    for i in range(n):
        if a[i] != mx:
            if x == 0:
                x = abs(mx - a[i])
            else:
                x = math.gcd(x, abs(mx - a[i]))
    t = mx - x
    while t in b:
        t -= x
    a.append(t)
    res = 0
    for i in range(n+1):
        if a[i] != mx:
            res += abs(mx - a[i])// x
    print(res)
    