import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    is_sorted = True
    for i in range(n-1):
        if a[i] > a[i+1]:
            is_sorted = False
    if is_sorted or k >= 2:
        print('YES')
    else:
        print('NO')