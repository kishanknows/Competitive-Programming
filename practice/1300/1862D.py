import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    x = int((2*n)**0.5)
    while(x * (x-1) <= 2*n):
        x += 1
    x -= 1
    print(x + n - x*(x-1)//2)
