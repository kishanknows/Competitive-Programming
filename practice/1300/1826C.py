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

#Pre calculating minimum divisor for a given number
#Algo is called Sieve of Eratosthenes
N = 1000001
min_divisor = [0]*N
for i in range(2, N):
    if min_divisor[i] == 0:
        min_divisor[i] = i
    for j in range(i, N, i):
        if min_divisor[j] == 0:
            min_divisor[j] = i
min_divisor[1] = 1

for _ in range(int(input())):
    n, m = map(int, input().split())
    print(['NO', 'YES'][min_divisor[n] > m or n == 1])