import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    a = [tuple(map(int, input().split())) for _ in range(n)]
    i = 0; j = 10**9
    while(i < j):
        k = (i + j)//2
        is_possible = True
        p = 0; q = 0
        for l, r in a:
            p = max(p-k, l)
            q = min(q+k, r)
            if p > q: 
                is_possible = False
                break
        if is_possible:
            j = k
        else:
            i = k+1
    print(j)

for _ in range(int(input())):
    solve()
