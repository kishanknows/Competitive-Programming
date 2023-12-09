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

@bootstrap
def min_ops(id, s, adj):
    l, r = adj[id]
    if l == -1 and r == -1:
        yield 0
    left = sys.maxsize; right = sys.maxsize
    if l != -1:
        left = yield min_ops(l, s, adj)
        if s[id] == 'L': left += 0
        else: left += 1
    if r != -1:
        right = yield min_ops(r, s, adj)
        if s[id] == 'R' : right += 0
        else : right += 1
    yield min(left, right)


for _ in range(int(input())):
    n = int(input())
    s = input()[:-1]
    adj = [[] for _ in range(n)]
    for i in range(n):
        l, r = map(int, input().split())
        adj[i].append(l-1)
        adj[i].append(r-1)
    print(min_ops(0, s, adj))
