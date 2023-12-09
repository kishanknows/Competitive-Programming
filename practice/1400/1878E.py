import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    q = int(input())
    b = [tuple(map(int, input().split())) for _ in range(q)]
    counter = [[0]*32 for _ in range(n+1)]
    for i, num in enumerate(a):
        mask = 1
        for j in range(31, -1, -1):
            counter[i+1][j] = counter[i][j] if num & mask else counter[i][j]+1
            mask <<= 1
    for l, k in b:
        i = l-1; j = n
        while i < j:
            r = (i + j)//2 + 1
            val = 0; pos = 1
            for p in range(31, -1, -1):
                if counter[r][p] - counter[l-1][p] == 0:
                    val += pos
                pos *= 2
            if val < k: j = r-1
            else: i = r
        print(i if i >= l else -1, end=' ')
    print('')

for _ in range(int(input())):
    solve()