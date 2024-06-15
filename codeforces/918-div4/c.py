import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    root = int(s**0.5)
    if s // root == root and s % root == 0:
        print("YES")
    else:
        print("NO")


for _ in range(int(input())):
    solve()
