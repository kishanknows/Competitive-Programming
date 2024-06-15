import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    s = input()[:-1]
    C = ["b", "c", "d"]
    V = ["a", "e"]
    res = []
    i = n - 1
    while i > 0:
        if s[i] in V:
            res.append(s[i])
            res.append(s[i - 1])
            res.append(".")
            i -= 2
        else:
            res.append(s[i])
            res.append(s[i - 1])
            res.append(s[i - 2])
            res.append(".")
            i -= 3
    res.reverse()
    print("".join(res[1:]))


for _ in range(int(input())):
    solve()
