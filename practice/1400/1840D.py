import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    a = sorted(list(map(int, input().split())))
    i = 0
    j = 10**9
    while i < j:
        t = (i + j) // 2
        count = 1
        prev = [a[0] - t, a[0] + t]
        for num in a:
            if prev[1] >= num - t:
                prev[0] = max(prev[0], num - t)
                prev[1] = min(prev[1], num + t)
            else:
                prev = [num - t, num + t]
                count += 1
        if count > 3:
            i = t + 1
        else:
            j = t
    print(i)


for _ in range(int(input())):
    solve()
