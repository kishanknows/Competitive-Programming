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
    n, p, l , t = map(int, input().split())
    total_tasks = n // 7 if n % 7 == 0 else n // 7 + 1

    res = 0
    days = (total_tasks // 2)
    temp = days*(2 * t + l)
    if temp >= p:
        res = p // (2* t + l) if p % (2*t + l) == 0 else p // (2*t+l) + 1
    else:
        res += days
        p -= temp
        if total_tasks % 2 == 1: 
            p -= (t+l)
            res += 1
        if p <= 0:
            print(n - res)
            continue
        else:
            res += p // l if p % l == 0 else p // l + 1
    print(n-res)
        