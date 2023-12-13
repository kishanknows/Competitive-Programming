import sys
input = sys.stdin.readline

def solve():
    n, m = map(int, input().split())
    a = [list(input()[:-1]) for _ in range(n)]
    for i in range(n):
        num = m - a[i].count('.')
        if num & 1:
            print(-1)
            return
    for j in range(m):
        count = 0
        for i in range(n):
            if a[i][j] == '.':
                count += 1
        num = n - count
        if num & 1:
            print(-1)
            return
    flag = True
    for i in range(n):
        for j in range(m):
            if a[i][j] == 'U':
                a[i][j] = 'B' if flag else 'W'
                a[i+1][j] = 'W' if flag else 'B'
                flag = not flag

    for j in range(m):
        for i in range(n):
            if a[i][j] == 'L':
                a[i][j] = 'B' if flag else 'W'
                a[i][j+1] = 'W' if flag else 'B'
                flag = not flag
    
    for i in range(n):
        print(''.join(a[i]))
    
for _ in range(int(input())):
    solve()