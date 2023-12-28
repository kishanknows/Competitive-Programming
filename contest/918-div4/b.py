import sys

input = sys.stdin.readline


def solve():
    a = input()[:-1]
    b = input()[:-1]
    c = input()[:-1]
    if "?" in a:
        if "A" not in a:
            print("A")
        if "B" not in a:
            print("B")
        if "C" not in a:
            print("C")
    if "?" in b:
        if "A" not in b:
            print("A")
        if "B" not in b:
            print("B")
        if "C" not in b:
            print("C")
    if "?" in c:
        if "A" not in c:
            print("A")
        if "B" not in c:
            print("B")
        if "C" not in c:
            print("C")


for _ in range(int(input())):
    solve()
