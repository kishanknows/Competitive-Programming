import sys

input = sys.stdin.readline


def solve():
    s = input()[:-1]
    n = len(s)
    i = n - 1
    while i > 0:
        while s[i] == "0":
            i -= 1
        if s[:i] == "":
            break
        if int(s[:i]) < int(s[i:]):
            print(s[:i], s[i:])
            return
        i -= 1
    print(-1)


for _ in range(int(input())):
    solve()
