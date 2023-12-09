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
    primes = []
    for num in a:
        while num % 2 == 0:
            primes.append(2)
            num //= 2
        for i in range(3, int(num**0.5)+1, 2):
            while num % i == 0:
                primes.append(i)
                num //= i
        if num > 2:
            primes.append(num)
    counts = Counter(primes)
    res = 0; odds = 0
    for value in counts.values():
        if value % 2 == 1:
            odds += 1
        res += value // 2
    print(res + odds // 3)