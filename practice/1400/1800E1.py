import sys
from collections import deque

input = sys.stdin.readline


def solve():
    n, k = map(int, input().split())
    s = input()[:-1]
    t = input()[:-1]
    s_sort = sorted(s)
    t_sort = sorted(t)
    if s_sort != t_sort:
        print("NO")
        return
    if n > 5:
        print("YES")
        return

    q = deque()
    st = set()
    q.append(s)
    while len(q):
        cur = q.popleft()
        st.add(cur)
        for i in range(n - k):
            tmp_copy = list(cur)
            tmp_copy[i + k], tmp_copy[i] = tmp_copy[i], tmp_copy[i + k]
            tmp_str = "".join(tmp_copy)
            if tmp_str not in st:
                q.append(tmp_str)
            if i + k + 1 < n:
                tmp_copy = list(cur)
                tmp_copy[i + k + 1], tmp_copy[i] = tmp_copy[i], tmp_copy[i + k + 1]
                tmp_str = "".join(tmp_copy)
                if tmp_str not in st:
                    q.append(tmp_str)
    if t in st:
        print("YES")
    else:
        print("NO")


for _ in range(int(input())):
    solve()
