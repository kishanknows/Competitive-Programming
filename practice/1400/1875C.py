import sys
input = sys.stdin.readline

def solve():
    n, m = map(int, input().split())
    init = n % m
    if init == 0:
        print(0)
        return
    max_ops = 300
    res = 0
    while max_ops:
        while init < m and max_ops:
            res += init
            init *= 2
            max_ops -= 1
        if init % m == 0:
            print(res)
            return
        else:
            init = init - m
    print(-1)

for _ in range(int(input())):
    solve()