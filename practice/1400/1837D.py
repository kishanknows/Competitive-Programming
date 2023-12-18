import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    s = input()[:-1]
    if 2 * s.count("(") != n:
        print(-1)
        return
    res = []
    i = 0
    r = 1 if s[0] == ")" else 2
    f = 1 if s[0] == "(" else 2
    while i < n:
        if s[i] == ")":
            res.append(r)
            i += 1
            count = -1
            while count != 0:
                res.append(r)
                count += 1 if s[i] == "(" else -1
                i += 1
        else:
            res.append(f)
            i += 1
            count = 1
            while count != 0:
                res.append(f)
                count += 1 if s[i] == "(" else -1
                i += 1
    print(len(set(res)))
    print(*res)


for _ in range(int(input())):
    solve()
