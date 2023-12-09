import sys
from collections import Counter
input = sys.stdin.readline

def solve():
    n = int(input())
    s = [list(map(int, input().split()))[1:] for i in range(n)]
    mp = Counter([item for sub_list in s for item in sub_list])
    res = 0
    for key in mp.keys():
        tmp = Counter([item for sub_list in s for item in sub_list if key not in sub_list])
        res = max(res, len(tmp))
    print(res)

T = int(input())
for t in range(T):
   solve()