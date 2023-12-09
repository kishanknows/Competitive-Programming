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
    n = int(input())
    a = [0] + list(map(int, input().split()))
    res = []
    orig_perm = {i for i in range(1, n+1)}
    perm = [a[i]-a[i-1] for i in range(1, n)]
    for val in perm:
        if val in orig_perm:
            orig_perm.remove(val)
        else:
            res.append(val)
    if len(res) == 0:
        print('YES')
    elif len(res) != 1 or len(orig_perm) != 2:
        print('NO')
    elif sum(orig_perm) == res[0]:
        print('YES')
    else:
        print('NO')