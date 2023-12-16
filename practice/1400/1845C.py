import sys

input = sys.stdin.readline


def solve():
    s = input()[:-1]
    m = int(input())
    l = input()[:-1]
    r = input()[:-1]
    start = 0
    mx = -1
    for i in range(m):
        digits = int(r[i]) - int(l[i]) + 1
        for d in range(digits):
            ch = chr(ord(l[i]) + d)
            id = s[start:].find(ch)
            if id == -1:
                print("YES")
                return
            mx = max(mx, id + start)
        start = mx + 1
    print("NO")


for _ in range(int(input())):
    solve()
