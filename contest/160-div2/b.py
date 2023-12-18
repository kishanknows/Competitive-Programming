import sys

input = sys.stdin.readline


def solve():
    s = input()[:-1]
    ones = s.count("1")
    zeros = s.count("0")
    res = 0
    for ch in s:
        if ch == "1":
            zeros -= 1
        else:
            ones -= 1
        if ones >= 0 and zeros >= 0:
            res += 1
    print(len(s) - res)


for _ in range(int(input())):
    solve()
