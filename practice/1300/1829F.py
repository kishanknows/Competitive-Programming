import sys
from types import GeneratorType
input = sys.stdin.readline

def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc

for _ in range(int(input())):
    n, m = map(int, input().split())
    adj = [[] for _ in range(n+1)]
    for i in range(m):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    x = -1; y = -1
    should_exit = False
    for i in range(1, n+1):
        if len(adj[i]) == 1:
            y = len(adj[adj[i][0]])-1
            for j in adj[adj[i][0]]:
                if len(adj[j]) != 1:
                    x = len(adj[j])
                    should_exit = True
                    break
        if should_exit: break
    print(x, y)
