import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [1] + list(map(int, input().split()))
    b = list(map(int, input().split()))
    a = sorted(a); b = sorted(b)
    j = 0; res = 0
    for i in range(n):
        while j < n and b[j] <= a[i]:
            j += 1
            res += 1
        j += 1
    print(res)