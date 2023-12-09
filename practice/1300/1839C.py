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
    if a[-1] == 1:
        print('NO')
        continue
    res = []
    i = n
    while i > 0:
        if a[i] == 0:
            res.append(0)
        else:
            count = 1
            while i > 0 and a[i-1] != 0:
                res.append(0)
                count += 1
                i -= 1
            res.append(count)
        i -= 1
    print('YES')
    print(*res)