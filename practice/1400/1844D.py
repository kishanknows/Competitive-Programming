import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    c = 1
    while n % c == 0:
        c += 1
    res = [chr(ord("a") + i % c) for i in range(n)]
    print("".join(res))


for _ in range(int(input())):
    solve()
