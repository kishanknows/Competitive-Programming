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
    a = list(map(int, input().split()))
    mx = max(a)
    if mx < 0:
        print(mx)
        continue
    even_sum = sum(a[i] for i in range(n) if i&1 == 0 and a[i] > 0)
    odd_sum = sum(a[i] for i in range(n) if i&1 == 1 and a[i] > 0)
    print(max(even_sum, odd_sum))