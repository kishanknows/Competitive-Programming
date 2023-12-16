import sys
from collections import deque

input = sys.stdin.readline


def solve():
    n = int(input())
    s = list(input()[:-1])
    if s == sorted(s):
        print(0)
        return
    st = sorted([(ch, i) for i, ch in enumerate(s)], key=lambda x: x[0], reverse=True)
    q = deque()
    idx = []
    prev = -1
    for val, id in st:
        if id > prev:
            q.append(val)
            idx.append(id)
            prev = id
    tmp = deque(q)
    tmp.reverse()
    if list(tmp) != sorted(q):
        print(-1)
        return
    res = 0
    qt = []
    while q[0] > q[-1]:
        res += 1
        ch = q.pop()
        qt.append(ch)
    while len(q):
        ch = q.popleft()
        qt.append(ch)
    for i, ix in enumerate(idx):
        s[ix] = qt[i]
    if s != sorted(s):
        print(-1)
        return
    print(res)


for _ in range(int(input())):
    solve()
