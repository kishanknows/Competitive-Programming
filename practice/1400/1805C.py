import sys
import bisect

input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    slopes = sorted([int(input()) for _ in range(n)])
    for _ in range(m):
        a, b, c = map(int, input().split())
        if a * c <= 0:
            print("NO")
            continue
        d = (4 * a * c) ** 0.5
        k1 = bisect.bisect_left(slopes, b + d)
        k2 = bisect.bisect_right(slopes, b - d)
        if k1 != k2:
            print(f"YES\n{slopes[k2]}")
            continue
        print("NO")


for _ in range(int(input())):
    solve()
