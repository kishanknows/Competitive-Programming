import sys

input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    res = [[i for i in range(j, j + m)] for j in range(1, n * m, m)]
    trans = [[i for i in range(j, m * n + 1, n)] for j in range(1, n + 1)]
    for i in range(2, m):
        if m % i == 0:
            for row in res:
                print(*row)
            return
    for i in range(2, n):
        if n % i == 0:
            for row in trans:
                print(*row)
            return
    pres = [[] for _ in range(n)]
    k = 0
    for i in range(0, n, 2):
        pres[i] = res[k]
        k += 1
    for j in range(1, n, 2):
        pres[j] = res[k]
        k += 1
    for row in pres:
        print(*row)


for _ in range(int(input())):
    solve()
