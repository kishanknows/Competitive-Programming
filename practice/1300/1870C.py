import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    res = [0]*k
    indices = [[] for _ in range(k)]
    for i in range(n):
        indices[a[i]-1].append(i)
    pre = n+1; post = -1
    for i in range(k-1, -1, -1):
        if not indices[i]: continue
        pre = min(pre, indices[i][0])
        post = max(post, indices[i][-1])
        res[i] = 2*(post-pre+1)
    print(*res)
    