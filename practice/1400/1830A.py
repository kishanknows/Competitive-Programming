import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    edges = [tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(n - 1)]
    adj = [[] for _ in range(n)]
    vis = [False] * n
    dp = [0] * n
    id = [0] * n
    dp[0] = 1
    indices = {}
    for i, (u, v) in enumerate(edges):
        indices[(u, v)] = i
        indices[(v, u)] = i
        adj[u].append(v)
        adj[v].append(u)
    # DFS
    stack = []
    stack.append(0)
    while len(stack):
        u = stack.pop()
        vis[u] = True
        for v in adj[u]:
            if vis[v]:
                continue
            if indices[(u, v)] >= id[u]:
                id[v] = indices[(u, v)]
                dp[v] = dp[u]
            else:
                id[v] = indices[(u, v)]
                dp[v] = dp[u] + 1
            stack.append(v)

    print(max(dp))


for _ in range(int(input())):
    solve()
