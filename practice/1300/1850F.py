import sys
from collections import Counter
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
    counts = [0]*(n+1); divisors = [0]*(n+1)
    for i in a:
        if i <= n: counts[i] += 1
    #suppose j == 8 then count_divisors[8] = counts[1] + counts[2] + counts[4] + counts[8]
    for i in range(1, n+1):
        for j in range(i, n+1, i):
            divisors[j] += counts[i]
    print(max(divisors))