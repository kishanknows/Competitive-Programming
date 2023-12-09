import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    d = 1
    res = []
    while n & (n-1) != 0:
        res.append(n)
        while n%d == 0:
            d *= 2
        d //= 2
        n -= d
    while n:
        res.append(n)
        n //= 2
    print(len(res))
    print(*res)