import sys
import math
from collections import Counter
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    counter = Counter()
    for num in a:
        prime_factors = []
        while(num%2 == 0):
            prime_factors.append(2)
            num //= 2
        for i in range(3, int(math.sqrt(num))+1, 2):
            while num%i == 0:
                prime_factors.append(i)
                num //= i
        if num > 2 :
            prime_factors.append(num)
        counter.update(prime_factors)
    res = "YES"
    for value in counter.values():
        if value%n != 0:
            res = "NO"
            break
    print(res)
      

      